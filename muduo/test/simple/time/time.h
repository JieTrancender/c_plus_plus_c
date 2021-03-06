#pragma once

#include <muduo/net/TcpServer.h>

#include <functional>

class TimeServer
{
public:
	TimeServer(muduo::net::EventLoop* loop, const muduo::net::InetAddress& listenAddr);
	void start();

private:
	void onConnection(const muduo::net::TcpConnectionPtr& conn);
	void onMessage(const muduo::net::TcpConnectionPtr& conn,
		muduo::net::Buffer* buf,
		muduo::Timestamp receiveTime);

	muduo::net::TcpServer server_;
};