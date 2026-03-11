#ifndef NYA_COMMON_UMATH_H
#define NYA_COMMON_UMATH_H

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning(disable: 4244) // conversion from 'const double' to 'T', possible loss of data
#endif

namespace UMath {
	class Vector2 {
	public:
		float x, y;
	};

#ifdef NYA_MATH_H
	class Vector3 : public NyaVec3 {
	public:
        using NyaVec3::NyaVec3;
		static inline auto& kZero = *(Vector3*)0x8A2FB4;
        
        Vector3(const NyaVec3& v) : NyaVec3(v) {}
	};

	class Vector4 : public NyaVec4 {
	public:
        using NyaVec4::NyaVec4;
		static inline auto& kIdentity = *(Vector4*)0x8A2FD0;
        
        Vector4(const NyaVec4& v) : NyaVec4(v) {}
	};

	class Matrix4 : public NyaMat4x4 {
	public:
        using NyaMat4x4::NyaMat4x4;
		static inline auto& kIdentity = *(Matrix4*)0x987AB0;
        
        Matrix4(const NyaMat4x4& m) : NyaMat4x4(m) {}
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

typedef UMath::Vector2 bVector2;
typedef UMath::Vector4 bVector4;
typedef UMath::Matrix4 bMatrix4;

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif