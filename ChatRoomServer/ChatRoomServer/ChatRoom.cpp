#include"ChatRoom.h"

//参与者进入聊天室，添加参与者，并对该参与者转发聊天室最近的
void ChatRoom::join(chat_participant_ptr participant) {
	participants_.insert(participant);
	cout << "新用户加入..." << endl;
	for (auto msg : recent_msgs_)
		participant->deliver(msg);
}

//参与者离开，擦除参与者指针
void ChatRoom::leave(chat_participant_ptr participant) {
	participants_.erase(participant);
	cout << "用户离开..." << endl;
}

void ChatRoom::deliver(const ChatMessage& msg) {
	//使用------------MySQL------------保存聊天历史记录
	//缓存方面，采用先进先出的方法存储最近max_recent_msgs条消息
	recent_msgs_.push_back(msg);
	while (recent_msgs_.size() > max_recent_msgs)
		recent_msgs_.pop_front();
	//对每一个参与者都进行转发
	for (auto participant : participants_)
		participant->deliver(msg);
}