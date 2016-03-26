#ifndef INCLUDE_APPSETTINGS_H_
#define INCLUDE_APPSETTINGS_H_

#include <user_config.h>
#include <SmingCore/SmingCore.h>


#define APP_SETTINGS_FILE ".settings.conf" // leading point for security reasons :)

#define DEFAULT_TCP_PORT 0
#define DEFAULT_MAVLINK_PORT 14550
#define DEFAULT_OTA_LINK FW_UPDATE_LINK
#define DEFAULT_MAVLINK_BAUDRATE 57600

//empty means autogenerated MAVBridge-<mac address>
#define DEFAULT_AP_SSID ""

//empty- open network
#define DEFAULT_AP_PASSWORD ""

#define RESTORE_PARAMETERS_PIN 0

class ApplicationSettingsStorage
{

public:
	String ssid;
	String password;

    String ap_password;
    String ap_ssid;
    
	bool dhcp = true;
    bool debug_output = false;

	IPAddress ip;
	IPAddress netmask;
	IPAddress gateway;

    /** Custom options
     */
    int baud_rate;

    int mav_port_in;
    int mav_port_out;

    int tcp_mav_port_in;

    String ota_link;

    void restore();

	void load();
	
	void save();

	bool exist();
};

extern ApplicationSettingsStorage AppSettings;

void app_settings_tick_10hz();

#endif /* INCLUDE_APPSETTINGS_H_ */
