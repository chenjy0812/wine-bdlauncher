#pragma once

#include "Actor.h"
#include <hook.h>
#include "../Core/ExtendedCertificate.h"
#include "../Core/Vec3.h"
#include "../Core/AutomaticID.h"

class Packet;
class ServerPlayer;

#ifndef BASEAPI
#  define BASEAPI __declspec(dllimport)
#endif

class Player : public Actor {
public:
  inline ServerPlayer *asServerPlayer() const noexcept {
    return const_cast<ServerPlayer *>(reinterpret_cast<ServerPlayer const *>(this));
  }

  inline void sendNetworkPacket(Packet &pkt) const {
    CallServerClassMethod<void>("?sendNetworkPacket@ServerPlayer@@UEBAXAEAVPacket@@@Z", this, &pkt);
  }

  void teleportTo(Vec3 const &vec, bool flag, int a, int b) const {
    CallServerClassMethod<void>("?teleportTo@Player@@UEAAXAEBVVec3@@_NHH@Z", this, &vec, flag, a, b);
  }

  BASEAPI Certificate &getCertificate();
};