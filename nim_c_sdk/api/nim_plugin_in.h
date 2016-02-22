/** @file nim_plugin.h
  * @brief NIM SDK�ṩ��plugin��������ӿ�
  * @copyright (c) 2015-2016, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/12/28
  */

#ifndef NIM_SDK_DLL_API_NIM_PLUGIN_IN_H_
#define NIM_SDK_DLL_API_NIM_PLUGIN_IN_H_

#include "nim_sdk_dll.h"
#include "nim_plugin_in_def.h"

#ifdef __cplusplus
extern"C"
{
#endif

/** @fn void nim_plugin_chatroom_request_enter_async(const __int64 room_id, const char *json_extension, nim_plugin_chatroom_request_enter_cb_func cb, const void *user_data)
  * �첽��ȡ���������ҵ���Ϣ
  * @param[in] room_id				������ID
  * @param[in] json_extension		json��չ���������ã�Ŀǰ����Ҫ��
  * @param[in] cb					�ص�����, �����nim_plugin_in_def.h
  * @param[in] user_data			APP���Զ����û����ݣ�SDKֻ���𴫻ظ��ص�����cb�������κδ���
  * @return void �޷���ֵ
  */
NIM_SDK_DLL_API void nim_plugin_chatroom_request_enter_async(const __int64 room_id, const char *json_extension, nim_plugin_chatroom_request_enter_cb_func cb, const void *user_data);

#ifdef __cplusplus
};
#endif //__cplusplus
#endif //NIM_SDK_DLL_API_NIM_PLUGIN_IN_H_