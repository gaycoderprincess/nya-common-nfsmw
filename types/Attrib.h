namespace Attrib {
	class Vault;

	class Collection {
	public:
		uint8_t _mTable[0xC];
		Collection* mParent;
		uint32_t mKey;
		void* mClass;
		void* mLayout;
		Vault* mSource;

		static inline auto GetData = (void*(__thiscall*)(Collection*, uint32_t attributeKey, uint32_t index))0x454190;
	};

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
	};

	auto FindCollection = (Collection*(__cdecl*)(uint32_t classKey, uint32_t collectionKey))0x455FD0;
	auto StringHash32 = (uint32_t(__cdecl*)(const char*))0x4519D0;
};