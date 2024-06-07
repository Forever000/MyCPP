#include"ChatRoom.h"

//�����߽��������ң���Ӳ����ߣ����Ըò�����ת�������������
void ChatRoom::join(chat_participant_ptr participant) {
	participants_.insert(participant);
	cout << "���û�����..." << endl;
	for (auto msg : recent_msgs_)
		participant->deliver(msg);
}

//�������뿪������������ָ��
void ChatRoom::leave(chat_participant_ptr participant) {
	participants_.erase(participant);
	cout << "�û��뿪..." << endl;
}

void ChatRoom::deliver(const ChatMessage& msg) {
	//ʹ��------------MySQL------------����������ʷ��¼
	//���淽�棬�����Ƚ��ȳ��ķ����洢���max_recent_msgs����Ϣ
	recent_msgs_.push_back(msg);
	while (recent_msgs_.size() > max_recent_msgs)
		recent_msgs_.pop_front();
	//��ÿһ�������߶�����ת��
	for (auto participant : participants_)
		participant->deliver(msg);
}