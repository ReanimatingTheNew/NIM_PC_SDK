﻿/** @file nim_talk_def.h
  * @brief NIM SDK talk相关的定义
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/02/02
  */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_TALK_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_TALK_DEF_H_

#ifdef __cplusplus
extern"C"
{
#endif
/** @typedef void (*nim_talk_arc_cb_func)(const char *result, const void *user_data)
  * 发送消息回执的回调函数定义
  * @param[out] result		json string (Keys SEE MORE 『发送消息回执Json Keys』 as follows)
  * @param[out] user_data	APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_talk_arc_cb_func)(const char *result, const void *user_data);

/** @typedef void (*nim_talk_receive_cb_func)(const char *content, const char *json_extension, const void *user_data)
  * 接收消息的回调函数定义
  * @param[out] content			json string (Keys SEE MORE 『接收消息Json Keys』 as follows)
  * @param[out] json_extension	json扩展数据（备用）
  * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_talk_receive_cb_func)(const char *content, const char *json_extension, const void *user_data);

/** @name 接收消息Json Keys
  * 本地定义的error code如下：
  * kNIMResSuccess(200) : no error
  * kNIMLocalResMsgUrlInvalid(414) : url invalid
  * kNIMLocalResMsgFileExist(417) : local file has exists
  * for example: 
  * {"rescode": 200,
  *  "feature": 1,
  *  "content": "***"
  * }
  * @{
  */
static const char *kNIMMsgKeyLocalRescode			= "rescode";			/**< int,消息错误码(NIMResCode) */
static const char *kNIMMsgKeyLocalMsgFeature		= "feature";			/**< int,消息种类(NIMMessageFeature),SDK本地维护 */
static const char *kNIMMsgKeyLocalReceiveMsgContent = "content";			/**< json string,消息内容，协议定义的消息结构 */
/** @}*/ //接收消息Json Keys

/** @name 消息结构 Json Keys
  * 例子 {"client_msg_id" : "c0d1167459fc754098a531482b51a1da","local_res_path" : "","log_status" : 4,"log_sub_status" : 0,"msg_attach" : "","msg_body" : "发送文本消息正文", "msg_type" : 0, "resend_flag" : 0, "time" : 1437014897000, "to_accid" : "4045", "to_type" : 1}
  * @{
  */
//协议定义
static const char *kNIMMsgKeyToType			= "to_type";			/**< int,会话类型(NIMSessionType) */
static const char *kNIMMsgKeyToAccount		= "to_accid";			/**< string,消息接收方id,给自己发送消息时填写自己id */
static const char *kNIMMsgKeyFromAccount	= "from_id";			/**< string,消息发送方id,服务器填写,发送方不需要填写 */
static const char *kNIMMsgKeyFromClientType = "from_client_type";	/**< int,消息发送方客户端类型,服务器填写,发送方不需要填写 */
static const char *kNIMMsgKeyFromDeviceId	= "from_device_id";		/**< string,消息发送方设备id,服务器填写,发送方不需要填写 */
static const char *kNIMMsgKeyFromNick		= "from_nick";			/**< string,消息发送方昵称,服务器填写,发送方不需要填写 */
static const char *kNIMMsgKeyTime			= "time";				/**< long,消息时间戳(毫秒) */
static const char *kNIMMsgKeyType			= "msg_type";			/**< int,消息类型(NIMMessageType) */
static const char *kNIMMsgKeyBody			= "msg_body";			/**< string,消息正文,长度限制：5000字符 */
static const char *kNIMMsgKeyAttach			= "msg_attach";			/**< string,消息多媒体资源参数,不同类型多媒体参数不同,发送非多媒体消息时不需要填写 */
static const char *kNIMMsgKeyClientMsgid	= "client_msg_id";		/**< string,客户端消息id */
static const char *kNIMMsgKeyServerMsgid	= "server_msg_id";		/**< long,服务器端消息id */
static const char *kNIMMsgKeyResendFlag		= "resend_flag";		/**< int,消息重发标记位,第一次发送0,重发1 */
static const char *kNIMMsgKeyHistorySave	= "cloud_history";		/**< int,该消息是否存储云端历史,可选,仅对kNIMMessageTypeCustom有效，0:不支持,1:支持, 默认1 */
static const char *kNIMMsgKeyMsgRoaming		= "roam_msg";			/**< int,该消息是否支持漫游,可选,仅对kNIMMessageTypeCustom有效,0:不支持,1:支持, 默认1 */
static const char *kNIMMsgKeyMsgSync		= "sync_msg";			/**< int,该消息是否支持发送者多端同步,可选,仅对kNIMMessageTypeCustom有效,0:不支持,1:支持, 默认1 */
//本地定义
static const char *kNIMMsgKeyLocalFilePath			= "local_res_path";		/**< string,多媒体消息资源本地绝对路径,SDK本地维护,发送多媒体消息时必填 */
static const char *kNIMMsgKeyLocalTalkId			= "talk_id";			/**< string,会话id,发送方选填,接收方收到的是消息发送方id */
static const char *kNIMMsgKeyLocalResId				= "res_id";				/**< string,多媒体资源id,发送方选填,接收方收到的是客户端消息id */
static const char *kNIMMsgKeyLocalLogStatus			= "log_status";			/**< int,消息状态(NIMMsgLogStatus)  */
static const char *kNIMMsgKeyLocalLogSubStatus		= "log_sub_status";		/**< int,消息二级状态(NIMMsgLogSubStatus) */
/** @}*/ //消息结构 Json Keys

/** @name 发送消息回执Json Keys
  * @{
  */
static const char *kNIMSendArcKeyMsgId		= "msg_id";			/**< string,客户端消息id */
static const char *kNIMSendArcKeyTalkId		= "talk_id";		/**< string,会话id */
static const char *kNIMSendArcKeyRescode	= "rescode";		/**< int,消息错误码(NIMResCode) */
/** @}*/ //发送消息回执Json Keys

/** @name 多媒体资源参数通用键名定义，可替代不同类型多媒体所使用的相同的参数的键名.
  * @{
  */
static const char *kNIMMsgAttachKeyMd5		= "md5";			/**< string,资源MD5,发送方选填 */
static const char *kNIMMsgAttachKeySize		= "size";			/**< long,资源大小(KB),发送方选填 */
static const char *kNIMMsgAttachKeyUrl		= "url";			/**< long,资源URL, 发送方不需要填写 */
static const char *kNIMMsgAttachKeyExt		= "ext";			/**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
/** @}*/ //多媒体资源参数通用键名定义，可替代不同类型多媒体所使用的相同的参数的键名.

/** @name 图片类型多媒体资源参数键名定义
  * @{
  */
static const char *kNIMImgMsgKeyMd5		= "md5";			/**< string,资源MD5,发送方选填 */
static const char *kNIMImgMsgKeySize	= "size";			/**< long,资源大小(KB),发送方选填 */
static const char *kNIMImgMsgKeyWidth	= "w";				/**< int,图片宽度,发送方必填 */
static const char *kNIMImgMsgKeyHeight	= "h";				/**< int,图片高度,发送方必填 */
static const char *kNIMImgMsgKeyUrl		= "url";			/**< string,资源URL, 发送方不需要填写 */
static const char *kNIMImgMsgKeyExt		= "ext";			/**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
/** @}*/ //图片类型多媒体资源参数键名定义

/** @name 语音类型多媒体资源参数键名定义
  * @{
  */
static const char *kNIMAudioMsgKeyMd5		= "md5";			/**< string,资源MD5,发送方选填 */
static const char *kNIMAudioMsgKeySize		= "size";			/**< long,资源大小(KB),发送方选填 */
static const char *kNIMAudioMsgKeyDuration	= "dur";			/**< int,语音资源时间长度(毫秒),发送方必填 */
static const char *kNIMAudioMsgKeyUrl		= "url";			/**< string,资源URL, 发送方不需要填写 */
static const char *kNIMAudioMsgKeyExt		= "ext";			/**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
/** @}*/ //语音类型多媒体资源参数键名定义

/** @name 短视频类型多媒体资源参数键名定义
  * @{
  */
static const char *kNIMVideoMsgKeyMd5			= "md5";			/**< string,资源MD5,发送方选填 */
static const char *kNIMVideoMsgKeySize			= "size";			/**< long,资源大小(KB),发送方选填 */
static const char *kNIMVideoMsgKeyDisplayName	= "name";			/**< string,资源显示名,发送方选填,默认文件名 */
static const char *kNIMVideoMsgKeyDuration		= "dur";			/**< int,短视频资源时间长度(毫秒),发送方必填 */
static const char *kNIMVideoMsgKeyWidth			= "w";				/**< int,短视频画面宽度,发送方必填 */
static const char *kNIMVideoMsgKeyHeight		= "h";				/**< int,短视频画面高度,发送方必填 */
static const char *kNIMVideoMsgKeyUrl			= "url";			/**< string,资源URL, 发送方不需要填写 */
static const char *kNIMVideoMsgKeyExt			= "ext";			/**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
/** @}*/ //短视频类型多媒体资源参数键名定义

/** @name 文件类型多媒体资源参数键名定义
* @{
*/
static const char *kNIMFileMsgKeyMd5			= "md5";			/**< string,资源MD5,发送方选填 */
static const char *kNIMFileMsgKeySize			= "size";			/**< long,资源大小(KB),发送方选填 */
static const char *kNIMFileMsgKeyDisplayName	= "name";			/**< string,资源显示名,发送方选填,默认文件名 */
static const char *kNIMFileMsgKeyUrl			= "url";			/**< string,资源URL, 发送方不需要填写 */
static const char *kNIMFileMsgKeyExt			= "ext";			/**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
/** @}*/ //文件类型多媒体资源参数键名定义

/** @name 位置类型多媒体资源参数键名定义
  * @{
  */
static const char *kNIMLocationMsgKeyLatitude	= "lat";			/**< double,纬度 */
static const char *kNIMLocationMsgKeyLongitude	= "lng";			/**< double,经度 */
static const char *kNIMLocationMsgKeyTitle		= "title";			/**< string,位置信息 */
/** @}*/ //位置类型多媒体资源参数键名定义

/** @name Notification Msg Attach Keys
  * kNIMNotificationMsgKeyId对应的attach内容：
  * TEAM_INVITE    {"tinfo":tinfo,"invite":["a1", "a2"]} 
  * TEAM_KICK      {"kick":["a1", "a2"]} 
  * TEAM_LEAVE     {"accid":"a1"}
  * TEAM_UPDATE    tinfo json
  * TEAM_DISMISS   {"tid":tid}
  * @{
  */
static const char *kNIMNotificationMsgKeyId		= "id";			/**< int */
static const char *kNIMNotificationMsgKeyData	= "data";		/**< json object */
/** @}*/ //Notification Msg Attach Keys
#ifdef __cplusplus
};
#endif //__cplusplus
#endif //NIM_SDK_DLL_EXPORT_HEADERS_TALK_DEF_H_