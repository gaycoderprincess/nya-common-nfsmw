class UserProfile {
public:
	uint8_t _0[0x414];
	FEPlayerCarDB mCarStable; // +414
};

class cFrontendDatabase {
public:
	uint8_t _0[0x10];
	UserProfile* mUserProfile; // +10
};
auto& FEDatabase = *(cFrontendDatabase**)0x91CF90;