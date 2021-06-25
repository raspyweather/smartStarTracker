#define Log_InitModule(name) Serial.println("[Module] " name " started initialization")
#define Log_InitializedModule(name) Serial.println("[Module] " name " initialized successfully")

#define Log_Info(name, message) Serial.println("[Info][" name "]" message)
#define Log_Error(name, message) Serial.printf("[Info][" name "]" message)