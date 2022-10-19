#include "server-thread.h"


ServerThread::ServerThread(std::unique_ptr<EchoServer> server)
: _server(std::move(server)),
  _queue(10),
  _thread([this](){
      for (;;) {
          auto packet = _queue.pop();
          if (packet == nullptr)
              break;
          std::string response = _server->doit(packet->request);
          packet->response_promise.set_value(response);
      }
  })
{}

ServerThread::~ServerThread()
{
    _queue.push(std::shared_ptr<Packet>());
    _thread.join();
}

std::string ServerThread::write(const std::string& request)
{
    auto packet = std::make_shared<Packet>(request);
    auto response_future = packet->response_promise.get_future();

    _queue.push(packet);

    return response_future.get();
}
