class AICopManager {
public:
	auto SpawnPatrolCar() { auto f = (bool(__thiscall*)(AICopManager*))0x430D90; return f(this); }
	auto SpawnPursuitCar(IPursuit* ipursuit) { auto f = (bool(__thiscall*)(AICopManager*, IPursuit*))0x42EA90; return f(this, ipursuit); }
	auto SpawnCopCarNow(IPursuit* ipursuit) { auto f = (bool(__thiscall*)(AICopManager*, IPursuit*))0x426960; return f(this, ipursuit); }
	auto GetAvailableCopVehicleByClass(UCrc32 vehicleClass, bool bValidOnesOnly) { auto f = (IVehicle*(__thiscall*)(AICopManager*, UCrc32, bool))0x426610; return f(this, vehicleClass, bValidOnesOnly); }
	auto SpawnVehicleBehindTarget(IPursuit* ipursuit, IVehicle* availableCopCar) { auto f = (void(__thiscall*)(AICopManager*, IPursuit*, IVehicle*))0x426850; return f(this, ipursuit, availableCopCar); }
};
auto& TheOneCopManager = *(AICopManager**)0x90D5F4;