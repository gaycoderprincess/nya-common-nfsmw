namespace Attrib {
	class Vault;
	class Class;

	class Collection {
	public:
		uint8_t _mTable[0x10];
		Collection* mParent;
		Class* mClass;
		void* mLayout;
		uint32_t mRefCount;
		uint32_t mKey;
		Vault* mSource;
		char* mNamePtr;

		static inline auto GetData = (void*(__thiscall*)(Collection*, uint32_t attributeKey, uint32_t index))0x454190;
	};
	static_assert(sizeof(Collection) == 0x2C);

	class Instance {
	public:
		void* mInterface;
		Collection* mCollection;
		void* mLayoutPtr;
		uint32_t mMsgPort;
		uint32_t mFlags;

		Instance(const Collection* collection, uint32_t msgPort, void* pInterface) {
			((Instance*(__thiscall*)(Instance*, const Collection*, uint32_t, void*))0x452380)(this, collection, msgPort, pInterface);
		}
		~Instance() {
			((void(__thiscall*)(Instance*))0x45A430)(this);
		}

		static inline auto GetAttributePointer = (void*(__thiscall*)(Instance*, uint32_t attributeKey, uint32_t index))0x454810;
		static inline auto GetCollection = (uint32_t(__thiscall*)(Instance*))0x452430;
	};

	auto FindCollection = (Collection*(__cdecl*)(uint32_t classKey, uint32_t collectionKey))0x455FD0;
	auto StringHash32 = (uint32_t(__cdecl*)(const char*))0x4519D0;

	namespace Gen {
		class pvehicle : public Instance {
			struct _LayoutStruct {
				UMath::Vector4 TENSOR_SCALE;
				uint32_t MODEL;
				char* DefaultPresetRide;
				char* CollectionName;
				int engine_upgrades;
				int transmission_upgrades;
				int nos_upgrades;
				int brakes_upgrades;
				float MASS;
				int tires_upgrades;
				uint32_t VerbalType;
				int induction_upgrades;
				int chassis_upgrades;
				unsigned char HornType;
				unsigned char TrafficEngType;
			};
		};
	}
};