VERSION ?= 0.0.1

MARIADB_VERSION := 10.11.4
MARIADB_FOLDER := mariadb-${MARIADB_VERSION}-linux-systemd-x86_64
OS := $(shell uname -s)

.PHONY: prep
prep:
	@echo "Preparing build/bin for usage..."
	@sed -i 's/#define VERSION ".*/#define VERSION "$(VERSION)"/g' common/version.h
	@-cd build/bin && unlink assets
	@cd build/bin && ln -s ../../base/assets assets
	@cp -R -u -p base/login.ini build/bin/login.ini
	@cp -R -u -p base/eqemu_config.json build/bin/eqemu_config.json
	@mkdir -p build/bin/logs
	@mkdir -p build/bin/shared
	@echo "Done."

# Runs loginserver binary
.PHONY: loginserver
loginserver:
	cd build/bin && ./loginserver

# Runs shared_memory binary
.PHONY: shared
shared:
	cd build/bin && ./shared_memory

# Runs zone binary
.PHONY: zone
zone:
	cd build/bin && ./zone

# Runs world binary
.PHONY: world
world:
	@-rm build/bin/logs/world*.log
	cd build/bin && ./world

# Start mariaDB standalone
.PHONY: mariadb
mariadb:
	@-killall mariadbd
	cd build/bin/db/${MARIADB_FOLDER}/bin && ./mysqld_safe --defaults-file=${PWD}/build/bin/db/my.cnf &

# Backs up the database
.PHONY: backup-db
backup-db:
	@echo "Backing up the database and zipping it..."
	@-rm -rf build/bin/db/backup
	@-mkdir -p build/bin/db/backup
	cd build/bin/db/${MARIADB_FOLDER}/bin && ./mariabackup --defaults-file=${PWD}/build/bin/db/my.cnf --backup --user=${USER} --socket=${PWD}/build/bin/db/mysql/mysqld.sock --target-dir=${PWD}/build/bin/db/backup
	cd build/bin/db && tar -czvf backup.tar.gz backup
	@-rm -rf build/bin/db/backup
	@echo "Backup complete. The file is located at build/bin/db/backup.tar.gz"

# Restores the database
.PHONY: restore-db
restore-db:
	@echo "Restoring the database from backup..."
	@-mkdir -p build/bin/db/backup
	cd build/bin/db && tar -xf backup.tar.gz
	cd build/bin/db/${MARIADB_FOLDER}/bin && ./mariabackup --defaults-file=${PWD}/build/bin/db/my.cnf --prepare --user=${USER} --socket=${PWD}/build/bin/db/mysql/mysqld.sock --target-dir=${PWD}/build/bin/db/backup
	cd build/bin/db && rm -rf backup.tar.gz
	@echo "Restore complete."

# Initializes a standalone copy of mariadb-server
.PHONY: init-db
init-mariadb:
	@echo "Initializing a standalone copy of mariadb-server..."
	@-mkdir -p build/bin/db
	cd build/bin/db && wget https://mirrors.xtom.com/mariadb//mariadb-${MARIADB_VERSION}/bintar-linux-systemd-x86_64/${MARIADB_FOLDER}.tar.gz
	cd build/bin/db && tar -xf ${MARIADB_FOLDER}.tar.gz
	cd build/bin/db && rm -rf ${MARIADB_FOLDER}.tar.gz
	cp -R -u -p base/my.cnf build/bin/db/my.cnf
	cd build/bin/db/${MARIADB_FOLDER}/scripts && ./mariadb-install-db --defaults-file=${PWD}/build/bin/db/my.cnf --datadir=${PWD}/build/bin/db/data --basedir=${PWD}/build/bin/db/${MARIADB_FOLDER}
	@#cd build/bin/db/${MARIADB_FOLDER}/bin && ./mysqld_safe --initialize-insecure --datadir=${PWD}/build/bin/db/data --defaults-file=${PWD}/build/bin/db/my.cnf
	@echo "MariaDB is now initialized. Use 'make mariadb' to run it."
	
# CICD triggers this
.PHONY: set-variable
set-version:
	@echo "VERSION=${VERSION}" >> $$GITHUB_ENV	