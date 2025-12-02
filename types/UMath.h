namespace UMath {
	class Vector3 {
	public:
		float x, y, z;

		static inline auto& kZero = *(Vector3*)0x8A2FB4;
	};

	class Vector4 {
	public:
		float x, y, z, w;

		static inline auto& kIdentity = *(Vector4*)0x8A2FD0;
	};

	class Matrix4 {
	public:
		UMath::Vector4 _v0, _v1, _v2, _v3;

		static inline auto& kIdentity = *(Matrix4*)0x987AB0;
	};
}

class bVector3 : public UMath::Vector3 {
	float pad;
};

typedef UMath::Vector4 bVector4;
typedef UMath::Matrix4 bMatrix4;