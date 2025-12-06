class ResourceFile;

enum eGarageType {
	GARAGETYPE_NONE = 0,
	GARAGETYPE_MAIN_FE = 1,
	GARAGETYPE_CAREER_SAFEHOUSE = 2,
	GARAGETYPE_CUSTOMIZATION_SHOP = 3,
	GARAGETYPE_CUSTOMIZATION_SHOP_BACKROOM = 4,
	GARAGETYPE_CAR_LOT = 5,
};

class FEManager {
public:
	bool bSuppressControllerError;
	bool bAllowControllerError;
	bool bWantControllerError[8];
	const char* mFirstScreen;
	int mFirstScreenArg;
	unsigned int mFirstScreenMask;
	eGarageType mGarageType;
	eGarageType mPreviousGarageType;
	ResourceFile* mGarageBackground;
	bool mFirstBoot;
	int mEATraxDelay;
	bool mEATraxFirstButton;

	static inline auto& mInstance = *(FEManager**)0x91CAE0;
	static inline auto& mPauseRequest = *(uint32_t*)0x91CAE4;
};