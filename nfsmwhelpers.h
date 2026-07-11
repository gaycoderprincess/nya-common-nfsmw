#include <string>
#include <algorithm>

namespace NyaHelpers {
	uint32_t GetCarFEKey(uint32_t modelHash) {
		auto collection = Attrib::FindCollection(Attrib::StringHash32("pvehicle"), modelHash);
		if (!collection) return modelHash;

		if (auto type = (uint32_t*)collection->GetData(Attrib::StringHash32("frontend"), 0)) {
			return type[1];
		}
		return modelHash;
	}

	FECarRecord CreateStockCarRecord(const char* carModel) {
		uint32_t rideHash = Attrib::StringHash32(carModel);

		FECarRecord car;
		car.Handle = rideHash;
		car.FEKey = GetCarFEKey(rideHash);
		car.VehicleKey = rideHash;
		car.FilterBits = 0x10001;
		car.Customization = -1;
		car.CareerHandle = -1;
		return car;
	}

	FECustomizationRecord CreateStockCarCustomizations(uint32_t carModel) {
		FECustomizationRecord record;
		record.Default();

		FECarRecord tmp;
		tmp.FEKey = carModel;
		tmp.VehicleKey = carModel;
		RideInfo info;
		info.Init(tmp.GetType(), CarRenderUsage_Player, false, false);
		info.SetStockParts();
		record.WriteRideIntoRecord(&info);
		return record;
	}

	FECustomizationRecord CreateRandomCarCustomizations(uint32_t carModel) {
		FECustomizationRecord record;
		record.Default();

		FECarRecord tmp;
		tmp.FEKey = carModel;
		tmp.VehicleKey = carModel;
		RideInfo info;
		info.Init(tmp.GetType(), CarRenderUsage_Player, false, false);
		info.SetRandomParts();
		//info.SetRandomPaint();
		record.WriteRideIntoRecord(&info);
		return record;
	}

	FECarRecord* CreatePinkSlipCar(const char* presetName) {
		uint32_t rideHash = FEngHashString(presetName);
		auto cars = &FEDatabase->CurrentUserProfiles[0]->PlayersCarStable;
		for (auto& car : cars->CarTable) {
			if (car.Handle == rideHash) {
				return &car;
			}
		}
		return FEPlayerCarDB::CreateNewPresetCar(cars, presetName);
	}

	PresetCar CreatePresetCar(FECarRecord* record, FECustomizationRecord* customizations, const char* presetName) {
		std::string carTypeName = record->GetDebugName();
		std::transform(carTypeName.begin(), carTypeName.end(), carTypeName.begin(), [](char c){ return std::toupper(c); });

		PresetCar car;
		strcpy_s(car.CarTypeName, 32, carTypeName.c_str());
		strcpy_s(car.PresetName, 32, presetName);

		// does this work? it's int64 here
		car.FEKey = record->FEKey;
		car.VehicleKey = record->VehicleKey;

		car.FilterBits = record->FilterBits;
		car.PhysicsLevel = 0; // todo

		for (int i = 0; i < CARSLOTID_NUM; i++) {
			auto part = CarPartDatabase::GetCarPartByIndex(&CarPartDB, customizations->InstalledPartIndices[i]);
			car.PartNameHashes[i] = part ? part->GetPartNameHash() : 0;
		}
		return car;
	}

	SceneryGroup* FindSceneryGroupById(int id) {
		auto node = SceneryGroupList.HeadNode.Next;
		while (node != &SceneryGroupList.HeadNode) {
			if (node->GroupNumber == id) return node;
			node = node->Next;
		}
		return nullptr;
	}
}