namespace UMath {
#ifdef NYA_MATH_H
	class Vector3 : public NyaVec3 {
	public:
		static inline auto& kZero = *(Vector3*)0x8A2FB4;
	};

	class Vector4 : public NyaVec4 {
	public:
		static inline auto& kIdentity = *(Vector4*)0x8A2FD0;
	};

	class Matrix4 : public NyaMat4x4 {
	public:
		static inline auto& kIdentity = *(Matrix4*)0x987AB0;
	};
#else
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
#endif
}

#ifdef NYA_MATH_H
class bVector3 : public NyaVec3 {
	float pad;
};
#else
class bVector3 : public UMath::Vector3 {
	float pad;
};
#endif

typedef UMath::Vector4 bVector4;
typedef UMath::Matrix4 bMatrix4;