#include "server-thread.h"


ServerThread::ServerThread(RemoteAdapter* adapter)
: _adapter(adapter),
  _queue(10),
  _thread([this](){
      for (;;) {
          Packet* packet = _queue.pop();
          if (packet == nullptr)
              break;
          std::string response = _adapter->execute(packet->request);
          packet->response_promise.set_value(response);
      }
  })
{}

ServerThread::~ServerThread()
{
    _queue.push(nullptr);
    _thread.join();
}

std::string ServerThread::write(const std::string& request)
{
    Packet packet;
    packet.request = request;
    auto response_future = packet.response_promise.get_future();

    _queue.push(&packet);

    return response_future.get();
}
