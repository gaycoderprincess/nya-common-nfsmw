class AICopManager {
public:
	static inline auto SpawnPatrolCar = (bool(__thiscall*)(AICopManager*))0x430D90;
	static inline auto SpawnPursuitCar = (bool(__thiscall*)(AICopManager*, IPursuit*))0x42EA90;
	static inline auto SpawnCopCarNow = (bool(__thiscall*)(AICopManager*, IPursuit*))0x426960;
	static inline auto GetAvailableCopVehicleByClass = (IVehicle*(__thiscall*)(AICopManager*, UCrc32, bool))0x426610;
	static inline auto SpawnVehicleBehindTarget = (void(__thiscall*)(AICopManager*, IPursuit*, IVehicle*))0x426850;
};
auto& TheOneCopManager = *(AICopManager**)0x90D5F4;