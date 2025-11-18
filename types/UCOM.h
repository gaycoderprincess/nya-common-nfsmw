namespace UCOM {
	class Object;

	class IUnknown {
	public:
		Object* mCOMObject;

		virtual void _vt0() {};
	};
	static_assert(sizeof(IUnknown) == 0x8);
}