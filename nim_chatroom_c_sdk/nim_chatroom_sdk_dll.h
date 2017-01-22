/** @file nim_chatroom_sdk_dll.h
  * @brief ���嵼����
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @author Harrison
  * @date 2015/7/23
  */

// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� NIM_SDK_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// NIM_SDK_DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

// ���ļ�ֻ���嵼���꣬�����������κζ�����modified by HarrisonFeng, 2015.7.23

#if !defined(__GNUC__) && defined(NIM_SDK_EXPORTS)
# 	define NIM_SDK_DLL_API		__declspec(dllexport)
#elif !defined(__GNUC__) && !defined(NIM_SDK_EXPORTS)
# 	define NIM_SDK_DLL_API		__declspec(dllimport)
#elif defined(__GNUC__) && defined(NIM_SDK_EXPORTS)
#	define NIM_SDK_DLL_API		__attribute__((visibility("default")))
#else
#	define NIM_SDK_DLL_API
#endif