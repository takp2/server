#ifndef EQEMU_OPTIONS_H
#define EQEMU_OPTIONS_H

/**
 * Collects options on one object, because having a bunch of global variables floating around is
 * really ugly and just a little dangerous.
 */
class Options
{
public:
	/**
	* Constructor, sets the default options.
	*/
	Options() :
		allow_unregistered(true),
		dump_in_packets(false),
		dump_out_packets(false),
		encryption_mode(5),
		local_network("127.0.0.1"),
		network_ip("127.0.0.1"),
		reject_duplicate_servers(false),
		allow_password_login(true),
		allow_token_login(false),
		auto_create_accounts(false) { }

	/**
	* Sets allow_unregistered.
	*/
	inline void AllowUnregistered(bool b) { allow_unregistered = b; }

	/**
	* Returns the value of allow_unregistered.
	*/
	inline bool IsUnregisteredAllowed() const { return allow_unregistered; }

	/**
	* Sets dump_in_packets.
	*/
	inline void DumpInPackets(bool b) { dump_in_packets = b; }

	/**
	* Returns the value of dump_in_packets.
	*/
	inline bool IsDumpInPacketsOn() const { return dump_in_packets; }

	/**
	* Sets dump_out_packets.
	*/
	inline void DumpOutPackets(bool b) { dump_out_packets = b; }

	/**
	* Returns the value of dump_out_packets.
	*/
	inline bool IsDumpOutPacketsOn() const { return dump_out_packets; }

	/**
	* Sets encryption_mode.
	*/
	inline void EncryptionMode(int m) { encryption_mode = m; }

	/**
	* Returns the value of encryption_mode.
	*/
	inline int GetEncryptionMode() const { return encryption_mode; }

	/**
	* Sets local_network.
	*/
	inline void LocalNetwork(std::string n) { local_network = n; }

	/**
	* Sets local_network.
	*/
	inline void NetworkIP(std::string n) { network_ip = n; }

	/**
	* Return the value of local_network.
	*/
	inline std::string GetLocalNetwork() const { return local_network; }

	/**
	* Return the value of local_network.
	*/
	inline std::string GetNetworkIP() const { return network_ip; }

	/**
	* Sets account table.
	*/
	inline void AccountTable(std::string t) { account_table = t; }

	/**
	* Return the value of local_network.
	*/
	inline std::string GetAccountTable() const { return account_table; }

	/**
	* Sets world account table.
	*/
	inline void WorldRegistrationTable(std::string t) { world_registration_table = t; }

	/**
	* Return the value of world account table.
	*/
	inline std::string GetWorldRegistrationTable() const { return world_registration_table; }

	/**
	* Sets world admin account table.
	*/
	inline void WorldAdminRegistrationTable(std::string t) { world_admin_registration_table = t; }

	/**
	* Return the value of world admin account table.
	*/
	inline std::string GetWorldAdminRegistrationTable() const { return world_admin_registration_table; }

	/**
	* Sets world server type table.
	*/
	inline void WorldServerTypeTable(std::string t) { world_server_type_table = t; }

	/**
	* Return the value of world admin account table.
	*/
	inline std::string GetWorldServerTypeTable() const { return world_server_type_table; }

	/**
	* Sets world server type table.
	*/
	inline void LoginSettingTable(std::string t) { loginserver_setting_table = t; }

	/**
	* Return the value of world admin account table.
	*/
	inline std::string GetLoginSettingTable() const { return loginserver_setting_table; }

	/**
	* Sets whether we are rejecting duplicate servers or not.
	*/
	inline void RejectDuplicateServers(bool b) { reject_duplicate_servers = b; }

	/**
	* Returns whether we are rejecting duplicate servers or not.
	*/
	inline bool IsRejectingDuplicateServers() { return reject_duplicate_servers; }

	inline void AllowTokenLogin(bool b) { allow_token_login = b; }
	inline bool IsTokenLoginAllowed() const { return allow_token_login; }

	inline void AllowPasswordLogin(bool b) { allow_password_login = b; }
	inline bool IsPasswordLoginAllowed() const { return allow_password_login; }

	inline void AutoCreateAccounts(bool b) { auto_create_accounts = b; }
	inline bool CanAutoCreateAccounts() const { return auto_create_accounts; }

private:
	bool allow_unregistered;
	bool dump_in_packets;
	bool dump_out_packets;
	bool reject_duplicate_servers;
	bool allow_token_login;
	bool allow_password_login;
	bool auto_create_accounts;
	int encryption_mode;
	std::string local_network;
	std::string network_ip;
	std::string account_table;
	std::string world_registration_table;
	std::string world_admin_registration_table;
	std::string world_server_type_table;
	std::string loginserver_setting_table;
};

#endif

