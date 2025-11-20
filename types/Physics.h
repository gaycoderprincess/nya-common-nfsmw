namespace Physics {
	namespace Upgrades {
		class Tuning {
		public:
			float lowerBound;
			float upperBound;
			float position;
		};

		class Package {
			int Part[7];
			int Junkman;
		};
	}

	namespace Info {
		class Performance {
		public:
			float TopSpeed;
			float Handling;
			float Acceleration;
		};
	}

	class Tunings {
	public:
		enum Path {
			STEERING = 0,
			HANDLING = 1,
			BRAKES = 2,
			RIDEHEIGHT = 3,
			AERODYNAMICS = 4,
			NOS = 5,
			INDUCTION = 6,
			MAX_TUNINGS = 7,
		};

		float Value[MAX_TUNINGS];
	};
}
static_assert(sizeof(Physics::Upgrades::Tuning) == 0xC);
static_assert(sizeof(Physics::Tunings) == 0x1C);