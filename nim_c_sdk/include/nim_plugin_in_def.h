/** @file nim_chatroom_def.h
  * @brief NIM SDK CHATROOM����
  * @copyright (c) 2015-2016, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/12/24
  */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_CHATROOM_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_CHATROOM_DEF_H_

#ifdef __cplusplus
extern"C"
{
#endif
/** @typedef void (*nim_plugin_chatroom_request_enter_cb_func)(int error_code, const char *result, const void *user_data)
  * �����ȡ������������Ϣ�Ļص���������
  * @param[out] int			������
  * @param[out] result		��¼��Ϣ��ֱ����Ϊ�������������ҵ�¼�ӿ�
  * @param[out] json_extension	json��չ���ݣ����ã�
  * @param[out] user_data	APP���Զ����û����ݣ�SDKֻ���𴫻ظ��ص������������κδ���
  * @return void �޷���ֵ
  */
typedef void (*nim_plugin_chatroom_request_enter_cb_func)(int error_code, const char *result, const char *json_extension, const void *user_data);

#ifdef __cplusplus
};
#endif //__cplusplus
#endif //NIM_SDK_DLL_EXPORT_HEADERS_NIM_CHATROOM_DEF_H_