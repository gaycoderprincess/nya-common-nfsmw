namespace Attrib {
	class StringKey {
	public:
		uint64_t mHash64;
		uint32_t mHash32;
		const char* mString;
	};

	class Vault;
	class Collection;

	class Class {
	public:
		auto GetFirstCollection() { auto f = (uint32_t(__thiscall*)(Class*))0x456B00; return f(this); }
		auto GetNextCollection(uint32_t prev) { auto f = (uint32_t(__thiscall*)(Class*, uint32_t))0x456B20; return f(this, prev); }
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

		auto GetData(uint32_t attributeKey, uint32_t index) {
			auto f = (void*(__thiscall*)(Collection*, uint32_t attributeKey, uint32_t index))0x454190;
			return f(this, attributeKey, index);
		}
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

		auto GetAttributePointer(uint32_t attributeKey, uint32_t index) {
			auto f = (void*(__thiscall*)(Instance*, uint32_t attributeKey, uint32_t index))0x454810;
			return f(this, attributeKey, index);
		}
		auto GetCollection() { auto f = (uint32_t(__thiscall*)(Instance*))0x452430; return f(this); }
	};
	static_assert(sizeof(Instance) == 0x14);

	class Database {
	public:
		static inline auto& sThis = *(Database**)0x90DCBC;

		auto GetClass(uint32_t k) { auto f = (Class*(__thiscall*)(Database*, uint32_t))0x455BC0; return f(this, k); }
	};

	auto FindCollection = (Collection*(*)(uint32_t classKey, uint32_t collectionKey))0x455FD0;
	auto StringHash32 = (uint32_t(*)(const char*))0x4519D0;

	struct RefSpec {
		unsigned int mClassKey;
		unsigned int mCollectionKey;
		const Collection* mCollectionPtr;
	};
	static_assert(sizeof(RefSpec) == 0xC);
};