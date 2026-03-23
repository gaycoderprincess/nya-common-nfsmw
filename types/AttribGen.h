class AxlePair {
public:
	float Front;
	float Rear;

	float At(int i) const { return (&Front)[i]; }
};

struct TireEffectRecord {
	Attrib::RefSpec mEmitter;
	float mMinSpeed;
	float mMaxSpeed;
};

struct RoadNoiseRecord {
	float Frequency;
	float Amplitude;
	float MinSpeed;
	float MaxSpeed;
};

namespace Attrib {
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
			~pvehicle() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
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
			~frontend() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class tires : public Instance {
		public:
			struct _LayoutStruct {
			};

			//frontend(uint32_t collection, uint32_t msgPort, void* pInterface) {
			//	((frontend*(__thiscall*)(frontend*, uint32_t, uint32_t, void*))0x51E1A0)(this, collection, msgPort, pInterface);
			//}
			~tires() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class brakes : public Instance {
		public:
			struct _LayoutStruct {
			};

			//frontend(uint32_t collection, uint32_t msgPort, void* pInterface) {
			//	((frontend*(__thiscall*)(frontend*, uint32_t, uint32_t, void*))0x51E1A0)(this, collection, msgPort, pInterface);
			//}
			~brakes() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class chassis : public Instance {
		public:
			struct _LayoutStruct {
			};

			//frontend(uint32_t collection, uint32_t msgPort, void* pInterface) {
			//	((frontend*(__thiscall*)(frontend*, uint32_t, uint32_t, void*))0x51E1A0)(this, collection, msgPort, pInterface);
			//}
			~chassis() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class transmission : public Instance {
		public:
			struct _LayoutStruct {
			};

			//frontend(uint32_t collection, uint32_t msgPort, void* pInterface) {
			//	((frontend*(__thiscall*)(frontend*, uint32_t, uint32_t, void*))0x51E1A0)(this, collection, msgPort, pInterface);
			//}
			~transmission() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class simsurface : public Instance {
		public:
			struct _LayoutStruct {
				Private _Array_TireDriveEffects;
				TireEffectRecord TireDriveEffects[3];
				Private _Array_TireSlideEffects;
				TireEffectRecord TireSlideEffects[3];
				Private _Array_TireSlipEffects;
				TireEffectRecord TireSlipEffects[3];
				RoadNoiseRecord RenderNoise;
				const char * CollectionName;
				float GROUND_FRICTION;
				float ROLLING_RESISTANCE;
				float WORLD_FRICTION;
				float DRIVE_GRIP;
				float LATERAL_GRIP;
				float STICK;
				unsigned short WheelEffectFrequency;
				unsigned char WheelEffectIntensity;
			};

			simsurface() {}
			simsurface(uint32_t collection, uint32_t msgPort, void* pInterface) {
				((simsurface*(__thiscall*)(simsurface*, uint32_t, uint32_t, void*))0x467C30)(this, collection, msgPort, pInterface);
			}
			~simsurface() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};
	}
}