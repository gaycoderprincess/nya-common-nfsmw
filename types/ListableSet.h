namespace UTL {
	template<typename T>
	class Vector {
	public:
		T* mBegin;
		uint32_t mCapacity;
		uint32_t mSize;

		virtual ~Vector() {};

		T operator[](int i) { return mBegin[i]; }

		auto begin() {
			return mBegin;
		}
		auto size() {
			return mSize;
		}
		auto capacity() {
			return mCapacity;
		}
		auto empty() {
			return mSize == 0;
		}
		auto indexof(T* pos) {
			return pos - mBegin;
		}
		T get(uint32_t i) {
			if (mSize < i) return mBegin[i];
			__debugbreak();
		}
	};
	static_assert(sizeof(Vector<void*>) == 0x10);

	template<typename T, uint32_t capacity>
	class FixedVector : public Vector<T> {
	public:
		T mVectorSpace[capacity];
	};

	// UTL::ListableSet<IPlayer,12,enum ePlayerList,3>::_ListSet UTL::ListableSet<IPlayer,12,enum ePlayerList,3>::_mLists
	template <typename T, int count, typename E, int capacity, uintptr_t listAddress>
	class ListableSet {
	public:
		FixedVector<T*, count> _buckets[capacity];

		static inline auto& _mLists = *(ListableSet<T, count, E, capacity, listAddress>*)listAddress;

		static auto& GetList(E type) {
			return _mLists._buckets[type];
		}
		static T* First(E type) {
			auto list = GetList(type);
			if (list->mSize) return list->mBegin[0];
			return nullptr;
		}
		static T* Last(E type) {
			auto list = GetList(type);
			if (list->mSize) return list->mBegin[list->mSize-1];
			return nullptr;
		}
	};
}

namespace eastl {
	template<typename T>
	class vector {
	public:
		uint8_t _0[4]; // huh?
		T* mpBegin;
		T* mpEnd;
		T* mpCapacity;

		T operator[](int i) { return mpBegin[i]; }

		auto size() { return mpEnd - mpBegin; }
		auto empty() { return mpEnd == mpBegin; }
	};
	static_assert(sizeof(vector<void*>) == 0x10);
}