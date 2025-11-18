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

		virtual void _vf0() {};

		template<typename T>
		T* Find() {
			return ((T*(__thiscall*)(Object*, uint32_t))(0x5D59F0))(this, T::IHandle);
		}
	};

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