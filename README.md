# TAKP2

TAKP2 takes the TAKP source and adds RoF2 client support, among other features listed below.

Features include:
- ProjectEQ Loginserver Support
- RoF2 Client Support

## Installation

Check out [installer](https://github.com/takp2/installer).

## Contributing

**Editor**

- Download [Visual Studio Code](https://code.visualstudio.com/)
- Open your project in vscode.
- You should get a prompt to reopen the project in a dev container. Say yes. If you miss the prompt, click the bottom left area and a drop down will appear that lets you reopen in dev container.
- Once in the dev container, copy these contents to .vscode/settings.json

**Database**

- We'll be using a standalone binary mysql install for dev purposes.
- `make init-mariadb`. This will create build/bin/db and download/create a standalone copy of mariadb.
- `make mariadb`. This will start a mysql server.
- `mysql -u vscode -S build/bin/db/mysql/mysqld.sock`, Starts a mysql root console
- `CREATE DATABASE takp;` Create a database called takp
- `CREATE USER 'takp'@'127.0.0.1' IDENTIFIED BY 'takppass';` Create a user named takp with password takppass
- `GRANT ALL PRIVILEGES ON *.* TO 'takp'@'127.0.0.1';` Give it access to everything.
- Exit the console by pressing CTRL+C.
- `mysql -u takp -h 127.0.0.1 -p` Starts a myql takp user console, will prompt for password, type `takppass` and enter.
- Above worked? Awesome. CTRL+C to exit
- `unzip -p base/db.sql.zip | mysql -u vscode -S build/bin/db/mysql/mysqld.sock --database takp` Source a database

**Build**

- `make prep` This will create a build subfolder, and copy files from base. This can be ran multiple times, files are checked prior to copying.
- `make shared` This should show 2 messages in yellow and exit quickly.
- `make loginserver` This will lock the window on success, open a new terminal.
- `make world` Will spin up world, open a new terminal
- `make zone` Now we have a fully running server.

**Debugging**

(gdb) attach is a debug launch.json that you can attach to an already running instance.