namespace Attrib {
	class Vault;
	class Collection;

	class Class {
	public:
		static inline auto GetFirstCollection = (uint32_t(__thiscall*)(Class*))0x456B00;
		static inline auto GetNextCollection = (uint32_t(__thiscall*)(Class*, uint32_t))0x456B20;
	};

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

		Instance() {}

		Instance(const Collection* collection, uint32_t msgPort, void* pInterface) {
			((Instance*(__thiscall*)(Instance*, const Collection*, uint32_t, void*))0x452380)(this, collection, msgPort, pInterface);
		}
		~Instance() {
			((void(__thiscall*)(Instance*))0x45A430)(this);
		}

		static inline auto GetAttributePointer = (void*(__thiscall*)(Instance*, uint32_t attributeKey, uint32_t index))0x454810;
		static inline auto GetCollection = (uint32_t(__thiscall*)(Instance*))0x452430;
	};

	class Database {
	public:
		static inline auto& sThis = *(Database**)0x90DCBC;

		static inline auto GetClass = (Class*(__thiscall*)(Database*, uint32_t))0x455BC0;
	};

	auto FindCollection = (Collection*(__cdecl*)(uint32_t classKey, uint32_t collectionKey))0x455FD0;
	auto StringHash32 = (uint32_t(__cdecl*)(const char*))0x4519D0;

	struct RefSpec {
		unsigned int mClassKey;
		unsigned int mCollectionKey;
		const Collection* mCollectionPtr;
	};
	static_assert(sizeof(RefSpec) == 0xC);

	namespace Gen {
		class pvehicle : public Instance {
			struct _LayoutStruct {
				UMath::Vector4 TENSOR_SCALE;
				uint32_t MODEL;
				const char* DefaultPresetRide;
				const char* CollectionName;
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

			pvehicle(uint32_t collection, uint32_t msgPort, void* pInterface) {
				((pvehicle*(__thiscall*)(pvehicle*, uint32_t, uint32_t, void*))0x4E4EA0)(this, collection, msgPort, pInterface);
			}
		};

		class frontend : public Instance {
		public:
			struct _LayoutStruct {
				RefSpec cam_angle;
				RefSpec default_car;
				const char* CollectionName;
				float cam_damping;
				float cam_anim_speed;
				float cam_fov;
				float cam_blur;
				float cam_lookat_x;
				float cam_lookat_y;
				float cam_lookat_z;
				unsigned int region;
				float cam_orbit_vertical;
				unsigned int manufacturer;
				float cam_roll_angle;
				int cam_periods;
				int Cost;
				float cam_orbit_radius;
				float cam_orbit_horizontal;
				bool IsCustomizable;
				unsigned char UnlockedAt;
				bool cam_user_rotate;
			};

			frontend(uint32_t collection, uint32_t msgPort, void* pInterface) {
				((frontend*(__thiscall*)(frontend*, uint32_t, uint32_t, void*))0x51E1A0)(this, collection, msgPort, pInterface);
			}
		};
	}
};