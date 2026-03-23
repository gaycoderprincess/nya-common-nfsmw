namespace UCOM {
	class Object {
	public:
		class _IList {
			void* mpBegin;
			void* mpEnd;
			void* mpCapacity;
			uint8_t gapC[4];
		};

		_IList _mInterfaces;

		template<typename T>
		T* Find() {
			return ((T*(__thiscall*)(Object*, uint32_t))(0x5D59F0))(this, T::IHandle);
		}
		template<typename T>
		void Add(T* ref) {
			return ((void(__thiscall*)(Object*, uint32_t, T*))(0x5D7930))(this, T::IHandle, ref);
		}
		template<typename T>
		void Remove(T* ref) {
			return ((void(__thiscall*)(Object*, T*))(0x5D5A50))(this, ref);
		}
	};
	static_assert(sizeof(Object) == 0x10);

	class IUnknown {
	public:
		Object* mCOMObject;

		virtual void _vf0() {};

		template<typename T>
		bool QueryInterface(T** out) {
			auto p = mCOMObject->Find<T>();
			*out = p;
			return p != nullptr;
		}
	};
	static_assert(sizeof(IUnknown) == 0x8);
}