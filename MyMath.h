#pragma once
#include <Windows.h>
#include <cstdint>
#include <string>
#include <format>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>
#include <dxcapi.h>
#include <cassert>

struct Vector2
{
	float x;
	float y;
};
struct Vector3
{
	float x;
	float y;
	float z;
};
struct Vector4
{
	float x;
	float y;
	float z;
	float w;
};
struct Matrix4x4 {
	float m[4][4];
};
struct Transform {
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
};
struct VertexData {
	Vector4 position;
	Vector2 texcoord;
};

float Cot(float a);

//積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

//平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
//拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

//  X軸回転
Matrix4x4 MakeRotateXMatrix(float radian);
// Y軸回転
Matrix4x4 MakeRotateYMatrix(float radian);
// Z軸回転
Matrix4x4 MakeRotateZMatrix(float radian);
// 回転行列
Matrix4x4 MakeRotateMatrix(const Vector3& radian);

//アフィン行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

//単位行列
Matrix4x4 MakeIdenttity4x4();

//逆行列
Matrix4x4 Inverse(const Matrix4x4& m);

//透視投影行列
Matrix4x4 MakePerspecriveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

//正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);