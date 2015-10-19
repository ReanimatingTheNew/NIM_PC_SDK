﻿/** @file nim_msglog_def.h
  * @brief msglog define
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/02/12
  */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_MSGLOG_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_MSGLOG_DEF_H_

#include "nim_session_def.h"

#ifdef __cplusplus
extern"C"
{
#endif
/** @typedef void (*nim_msglog_query_cb_func)(int res_code, const char *id, NIMSessionType type, const char *result, const char *json_extension, const void *user_data)
  * 本地或在线查询消息的回调函数定义
  * @param[out] res_code		操作结果，成功200
  *								1. 在线查询双人会话消息需要处理的错误号：
  *								414:参数错误
  *								2. 在线查询群组消息需要处理的错误号：
  *								414:参数错误 
  *								403:禁止访问(不在该群)
  * @param[out] id				查询时传入的对方account id或者群组tid
  * @param[out] type 			查询时传入的会话类型
  * @param[out] result			查询结果json object array string (SEE MORE 『查询消息历史结果Json Keys』 as follows)（查询结果的实际数量需要解析该结果获取）
  * @param[out] json_extension	json扩展数据（备用）
  * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
typedef void (*nim_msglog_query_cb_func)(int res_code, const char *id, NIMSessionType type, const char *result, const char *json_extension, const void *user_data);

/** @typedef void (*nim_msglog_res_cb_func)(int res_code, const char *msg_id, const char *json_extension, const void *user_data)
  * 消息历史操作结果的回调函数定义
  * @param[out] res_code		操作结果，成功200
  * @param[out] msg_id			消息历史id
  * @param[out] json_extension	json扩展数据（备用）
  * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_msglog_res_cb_func)(int res_code, const char *msg_id, const char *json_extension, const void *user_data);

/** @typedef void (*nim_msglog_res_ex_cb_func)(int res_code, const char *uid, NIMSessionType to_type, const char *json_extension, const void *user_data)
  * 消息历史操作结果的回调函数定义
  * @param[out] res_code	操作结果，成功200
  * @param[out] uid			对象id(account_id , team_id etc.)
  * @param[out] to_type		对象类型(好友， 群组 etc.)
  * @param[out] json_extension json扩展数据（备用）
  * @param[out] user_data	APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_msglog_res_ex_cb_func)(int res_code, const char *uid, NIMSessionType type, const char *json_extension, const void *user_data);

/** @typedef void (*nim_msglog_import_prg_cb_func)(__int64 imported_count, __int64 total_count, const char *json_extension, const void *user_data)
  * nim callback function for message log import progress
  * @param[out] imported_count 		已导入的消息历史记录数目
  * @param[out] total_count			消息历史记录总数目
  * @param[out] json_extension		json扩展数据（备用）
  * @param[out] user_data			APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_msglog_import_prg_cb_func)(__int64 imported_count, __int64 total_count, const char *json_extension, const void *user_data);

/** @name 查询消息历史结果Json Keys
  * for example: 
  * {"count": 20,
  *  "content":[***]
  * }
  * @{
  */
static const char *kNIMMsglogQueryKeyCount		= "count";			/**< int, 查询得到的数量 */
static const char *kNIMMsglogQueryKeyContent	= "content";		/**< json object array (Keys SEE MORE in `nim_talk_def.h` 『消息结构 Json Keys』)，查询得到的msglog内容 */
/** @}*/ //查询消息历史结果Json Keys

/** @enum NIMMessageType Message Type */
enum NIMMessageType
{
	kNIMMessageTypeText      = 0,			/**< 文本类型消息*/
	kNIMMessageTypeImage     = 1,			/**< 图片类型消息*/ 
	kNIMMessageTypeAudio     = 2,			/**< 声音类型消息*/ 
	kNIMMessageTypeVideo     = 3,			/**< 视频类型消息*/
	kNIMMessageTypeLocation  = 4,			/**< 位置类型消息*/
	kNIMMessageTypeNotification	= 5,		/**< 系统类型通知（包括入群出群通知等） NIMNotificationId*/
	kNIMMessageTypeFile		 = 6,			/**< 文件类型消息*/
	kNIMMessageTypeCustom    = 100,			/**< 自定义消息*/

	kNIMMessageTypeUnknown	 = 1000,		/**< 未知类型消息，作为默认值*/
};

/** @enum NIMMessageFeature Message Feature */
enum NIMMessageFeature
{
	kNIMMessageFeatureDefault	= 0,			/**< 默认*/
	kNIMMessageFeatureLeaveMsg	= 1,			/**< 离线消息*/
	kNIMMessageFeatureRoamMsg	= 2,			/**< 漫游消息*/
	kNIMMessageFeatureSyncMsg	= 3,			/**< 同步消息*/
	kNIMMessageFeatureCustomizedMsg	= 4,		/**< 透传消息*/
};

/** @enum NIMMsgLogStatus Message Log Status */
enum NIMMsgLogStatus
{
	kNIMMsgLogStatusNone		= 0,			/**< 默认,不能当查询条件,意义太多*/
	kNIMMsgLogStatusUnread		= 1,			/**< 收到消息,未读*/ 
	kNIMMsgLogStatusRead		= 2,			/**< 收到消息,已读*/ 
	kNIMMsgLogStatusDeleted		= 3,			/**< 已删*/ 
	kNIMMsgLogStatusSending		= 4,			/**< 发送中*/
	kNIMMsgLogStatusSendFailed	= 5,			/**< 发送失败*/ 
	kNIMMsgLogStatusSent		= 6,			/**< 已发送*/ 
	kNIMMsgLogStatusReceipt		= 7,			/**< 对方已读发送的内容*/ 
	kNIMMsgLogStatusDraft		= 8,			/**< 草稿*/
	kNIMMsgLogStatusSendCancel	= 9,			/**< 发送取消*/
};

/** @enum NIMNotificationId Notification Id */
enum NIMNotificationId
{
	kNIMNotificationIdTeamInvite			= 0,			/**< 普通群拉人，{"ids":["a1", "a2"]}*/
	kNIMNotificationIdTeamKick				= 1,			/**< 普通群踢人，{"ids":["a1", "a2"]}*/
	kNIMNotificationIdTeamLeave				= 2,			/**< 退出群，{"id" : "a1"}*/
	kNIMNotificationIdTeamUpdate			= 3,			/**< team_info更新，{"team_info":team_info} //群组信息(Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)*/
	kNIMNotificationIdTeamDismiss			= 4,			/**< 群解散，{}*/
	kNIMNotificationIdTeamApplyPass			= 5,			/**< 高级群申请加入成功，{"id":"a1"}*/
	kNIMNotificationIdTeamOwnerTransfer		= 6,			/**< 高级群移交群主，{"id":"a1", "leave" : bool}*/
	kNIMNotificationIdTeamAddManager		= 7,			/**< 增加管理员，{"ids":["a1","a2"]}*/
	kNIMNotificationIdTeamRemoveManager		= 8,			/**< 删除管理员，{"ids":["a1","a2"]}*/
	kNIMNotificationIdTeamInviteAccept		= 9,			/**< 高级群接受邀请进群，{"id":"a1"}*/

	kNIMNotificationIdNetcallMiss			= 101,			/**< 未接电话,{"calltype":1,"channel":6146078138783760761,"from":"id1","ids":["id1","id2"],"time":1430995380471}*/
	kNIMNotificationIdNetcallBill			= 102,			/**< 话单,{"calltype":2,"channel":6146077129466446197,"duration":8,"ids":["id1","id2"],"time":1430995117398}*/
	
	//服务器在线同步协议返回的结果
	kNIMNotificationIdTeamSyncCreate		= 1000,			/**< 创建群 {"team_info" : team_info} //群组信息(Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)*/
	kNIMNotificationIdTeamMemberChanged		= 1001,			/**< 群成员变更{"team_member" : team_member_info} //群组成员信息（不包括自己）(Keys SEE MORE `nim_team_def.h` 『群组成员信息 Json Keys』)*/
	kNIMNotificationIdTeamSyncUpdateTlist	= 1002,			/**< 同步通知：修改群属性（可能是自己的或别人的）{"team_member" : team_member_info} //目前只需kNIMTeamUserKeyNick和kNIMTeamUserKeyBits (Keys SEE MORE `nim_team_def.h` 『群组成员信息 Json Keys』)*/

	//本地操作通知APP上层
	kNIMNotificationIdLocalCreateTeam		= 2000,			/**< 本地操作创建群 {"ids" : ["a1", "a2"]}*/
	kNIMNotificationIdLocalApplyTeam		= 2001,			/**< 本地操作申请加入群 {}*/
	kNIMNotificationIdLocalRejectApply		= 2002,			/**< 本地操作拒绝申请 {"id":"a1"}*/
	kNIMNotificationIdLocalRejectInvite		= 2003,			/**< 本地操作拒绝邀请 {"id":"a1"}*/
	kNIMNotificationIdLocalUpdateTlist		= 2004,			/**< 本地操作更新tlist  {"team_member" : team_member_info}，目前只需kNIMTeamUserKeyNick和kNIMTeamUserKeyBits*/  
	kNIMNotificationIdLocalUpdateOtherNick	= 2005,			/**< 本地操作更新他人nickname {}*/
	kNIMNotificationIdLocalGetTeamInfo		= 2006,			/**< 本地操作获取群信息 {"team_info":team_info} //群组信息(Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)*/
	kNIMNotificationIdLocalGetTeamList		= 2007,			/**< 本地操作获取群成员信息结束*/
	//Netcall本地操作通知
	kNIMNotificationIdLocalNetcallReject	= 3103,			/**< 拒绝电话,{"calltype":1,"channel":6146078138783760761,"from":"id1","ids":["id1","id2"],"time":1430995380471}*/
	kNIMNotificationIdLocalNetcallNoResponse= 3104,			/**< 无应答，未接通电话,{"calltype":1,"channel":6146078138783760761,"from":"id1","ids":["id1","id2"],"time":1430995380471}*/
};

/** @enum NIMMsgLogSubStatus 消息子状态 */
enum NIMMsgLogSubStatus
{
	kNIMMsgLogSubStatusNone                 = 0,			/**< 默认状态*/

	//这二个标志适用于所有
	kNIMMsgLogSubStatusNotPlaying           = 20,			/**< 未播放*/
	kNIMMsgLogSubStatusPlayed               = 21,			/**< 已播放*/
};

/** @enum NIMMsgLogQueryRange 消息历史的检索范围 */
enum NIMMsgLogQueryRange
{
	kNIMMsgLogQueryRangeP2P                 = kNIMSessionTypeP2P,	/**< 指定的个人（点对点会话）（注意：暂不支持指定多个人的检索！）*/
	kNIMMsgLogQueryRangeTeam				= kNIMSessionTypeTeam,	/**< 指定的群组（注意：暂不支持指定多个群组的检索！）*/

	kNIMMsgLogQueryRangeAll					= 100,					/**< 全部*/
	kNIMMsgLogQueryRangeAllP2P				= 101,					/**< 所有个人会话*/
	kNIMMsgLogQueryRangeAllTeam				= 102,					/**< 所有群组*/
	kNIMMsgLogQueryRangeUnknown				= 200,					/**< 未知（如指定个人和群组的集合）（注意：暂不支持指定个人和群组的混合检索！）*/
};

/** @name 群组通知 Json Keys
  * for example: 
  * {"id": 1, 
  *  "data": ***
  * }
  * @{
  */
static const char *kNIMNotificationKeyId		= "id";				/**< int, 见NIMNotificationId */
static const char *kNIMNotificationKeyData		= "data";			/**< json object (Keys as follows) */
static const char *kNIMNotificationKeyDataIds	= "ids";			/**< string array (20150505 RECOMMEND TO USE instead of using "ids" as follows) */
static const char *kNIMNotificationKeyDataId	= "id";				/**< string, (20150505 RECOMMEND TO USE instead of using "id" as follows) */
static const char *kNIMNotificationKeyTeamInfo	= "team_info";		/**< string,  team info json string (20150505 RECOMMEND TO USE instead of using "team_info" as follows) */
static const char *kNIMNotificationKeyTeamMember = "team_member";	/**< string,  team member info json string (20150505 RECOMMEND TO USE instead of using "team_member" as follows) */
/** @}*/ //群组通知 Json Keys

/** @name kNIMNotificationIdLocalGetTeamInfo Data Keys
  * @{
  */
static const char *kNIMNotificationGetTeamInfoKey	= "team_info";	/**< string */
/** @}*/ //kNIMNotificationIdLocalGetTeamInfo Data Keys

/** @name kNIMNotificationIdLocalCreateTeam Data Keys
  * @{
  */
static const char *kNIMNotificationCreateTeamKeyUids = "ids";	/**< string array */
/** @}*/ //kNIMNotificationIdLocalCreateTeam Data Keys

/** @name kNIMNotificationIdTeamInvite Data Keys
  * @{
  */
static const char *kNIMNotificationInviteKeyUids	= "ids";	/**< string array */
/** @}*/ //kNIMNotificationIdTeamInvite Data Keys

/** @name kNIMNotificationIdTeamLeave Data Keys
  * @{
  */
static const char *kNIMNotificationLeaveKeyUid		= "id";		/**< string */
/** @}*/ //kNIMNotificationIdTeamLeave Data Keys

/** @name kNIMNotificationIdTeamKick Data Keys
  * @{
  */
static const char *kNIMNotificationKickKeyUids		= "ids";	/**< string array */
/** @}*/ //kNIMNotificationIdTeamKick Data Keys

/** @name kNIMNotificationIdTeamUpdate Data Keys
  * @{
  */
static const char *kNIMNotificationUpdataKey		= "team_info";		/**< string */
/** @}*/ //kNIMNotificationIdTeamUpdate Data Keys

/** @name kNIMNotificationIdTeamApplyPass/Reject Data Keys
  * @{
  */
static const char *kNIMNotificationTeamApplyResUid		= "id";		/**< string */
/** @}*/ //kNIMNotificationIdTeamApplyPass/Reject Data Keys

/** @name kNIMNotificationIdTeamOwnerTransfer Data Keys
  * @{
  */
static const char *kNIMNotificationOwnerTransferUid		= "id";		/**< string */
static const char *kNIMNotificationOwnerTransferLeave	= "leave";	/**< bool */
/** @}*/ //kNIMNotificationIdTeamOwnerTransfer Data Keys

/** @name kNIMNotificationIdTeamAddManager Data Keys
  * @{
  */
static const char *kNIMNotificationAddManagerUids		= "ids";	/**< string array */
/** @}*/ //kNIMNotificationIdTeamAddManager Data Keys

/** @name kNIMNotificationIdTeamRemoveManager Data Keys
  * @{
  */
static const char *kNIMNotificationRemoveManagerUids	= "ids";	/**< string array */
/** @}*/ //kNIMNotificationIdTeamRemoveManager Data Keys

/** @name kNIMNotificationIdTeamInviteAccept/Reject Data Keys
  * @{
  */
static const char *kNIMNotificationInviteResUid		= "id";		/**< string */
/** @}*/ //kNIMNotificationIdTeamInviteAccept/Reject Data Keys

/** @name kNIMNotificationIdTeamMemberChanged Data Keys
  * @{
  */
static const char *kNIMNotificationIdTeamMemberChangedKey = "team_member";		/**< string */
/** @}*/ //kNIMNotificationIdTeamMemberChanged Data Keys

/** @name kNIMNotificationIdNetcallBill/kNIMNotificationIdNetcallMiss/kNIMNotificationIdLocalNetcallReject/kNIMNotificationIdLocalNetcallNoResponse Data Keys
  * @{
  */
static const char *kNIMNotificationIdNetCallTypeKey		= "calltype";		/**< int 通话类型对应NIMVideoChatMode */
static const char *kNIMNotificationIdNetCallTimeKey		= "time";			/**< int64 时间 单位毫秒 */
static const char *kNIMNotificationIdNetCallIdsKey		= "ids";			/**< StrArray 账号 */
static const char *kNIMNotificationIdNetCallChannelKey	= "channel";		/**< int64 通道id */
static const char *kNIMNotificationIdNetCallDurationKey = "duration";		/**< int64 通话时长 单位秒 */
static const char *kNIMNotificationIdNetCallFromKey		= "from";			/**< string 发起者账号 */
/** @}*/ //kNIMNotificationIdNetcallBill/kNIMNotificationIdNetcallMiss/kNIMNotificationIdLocalNetcallReject/kNIMNotificationIdLocalNetcallNoResponse Data Keys

#ifdef __cplusplus
};
#endif //__cplusplus
#endif //NIM_SDK_DLL_EXPORT_HEADERS_MSGLOG_DEF_H_