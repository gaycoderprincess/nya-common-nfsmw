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

struct CarBodyMotion {
	float DegPerG;
	float MaxGs;
	float DegPerSec;
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
				Private _Array_YAW_CONTROL;
				float YAW_CONTROL[4];
				AxlePair GRIP_SCALE;
				AxlePair DYNAMIC_GRIP;
				AxlePair ASPECT_RATIO;
				AxlePair RIM_SIZE;
				AxlePair STATIC_GRIP;
				AxlePair SECTION_WIDTH;
				float STEERING;
				float YAW_SPEED;
			};

			tires(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("tires"), collectionKey), 0, nullptr);
			}
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
				AxlePair BRAKE_LOCK;
				AxlePair BRAKES;
				float EBRAKE;
			};

			brakes(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("brakes"), collectionKey), 0, nullptr);
			}
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
				AxlePair SHOCK_DIGRESSION;
				AxlePair SPRING_PROGRESSION;
				AxlePair TRAVEL;
				AxlePair RIDE_HEIGHT;
				AxlePair TRACK_WIDTH;
				AxlePair SHOCK_EXT_STIFFNESS;
				AxlePair SHOCK_STIFFNESS;
				AxlePair SPRING_STIFFNESS;
				AxlePair SHOCK_VALVING;
				AxlePair SWAYBAR_STIFFNESS;
				float ROLL_CENTER;
				float WHEEL_BASE;
				float SHOCK_BLOWOUT;
				float AERO_CG;
				float RENDER_MOTION;
				float FRONT_AXLE;
				float AERO_COEFFICIENT;
				float FRONT_WEIGHT_BIAS;
				float DRAG_COEFFICIENT;
			};

			chassis(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("chassis"), collectionKey), 0, nullptr);
			}
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
				Private _Array_GEAR_RATIO;
				float GEAR_RATIO[9];
				Private _Array_DIFFERENTIAL;
				float DIFFERENTIAL[3];
				Private _Array_GEAR_EFFICIENCY;
				float GEAR_EFFICIENCY[9];
				float TORQUE_CONVERTER;
				float TORQUE_SPLIT;
				float CLUTCH_SLIP;
				float OPTIMAL_SHIFT;
				float SHIFT_SPEED;
				float FINAL_GEAR;
			};

			transmission(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("transmission"), collectionKey), 0, nullptr);
			}
			~transmission() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class ecar : public Instance {
		public:
			struct _LayoutStruct {
				Private _Array_TireOffsets;
				char _Pad_TireOffsets[8];
				UMath::Vector4 TireOffsets[4];
				Private _Array_TireSkidWidthKitScale;
				UMath::Vector2 TireSkidWidthKitScale[7];
				Private _Array_SkidFX;
				float SkidFX[2];
				CarBodyMotion BodyRoll;
				CarBodyMotion BodySquat;
				CarBodyMotion BodyDive;
				Private _Array_SlipFX;
				float SlipFX[2];
				Private _Array_TireSkidWidth;
				float TireSkidWidth[4];
				const char * CollectionName;
				float CamberFront;
				float ReflectionOffset;
				float CamberRear;
				float RideHeight;
				Private _Array_KitWheelOffsetRear;
				unsigned char KitWheelOffsetRear[6];
				Private _Array_KitWheelOffsetFront;
				unsigned char KitWheelOffsetFront[6];
				char WheelSpokeCount;
			};

			ecar(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("ecar"), collectionKey), 0, nullptr);
			}
			~ecar() {
				dtor();
			}

			_LayoutStruct* GetLayout() {
				return (_LayoutStruct*)mLayoutPtr;
			}
		};

		class camerainfo : public Instance {
		public:
			struct _LayoutStruct {
				Private _Array_STIFFNESS;
				float STIFFNESS[2];
				Private _Array_LATOFFSET;
				float LATOFFSET[2];
				Private _Array_LAG;
				float LAG[2];
				Private _Array_FOV;
				float FOV[2];
				Private _Array_HEIGHT;
				float HEIGHT[2];
				Private _Array_ANGLE;
				float ANGLE[2];
				const char * CollectionName;
				Private _Array_TILTING;
				bool TILTING[2];
				Private _Array_SELECTABLE;
				bool SELECTABLE[2];
			};

			camerainfo(uint32_t collectionKey) {
				ctor(Attrib::FindCollection(Attrib::StringHash32("camerainfo"), collectionKey), 0, nullptr);
			}
			~camerainfo() {
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