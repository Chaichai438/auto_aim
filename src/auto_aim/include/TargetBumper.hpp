#ifndef TARGETBUMPER_HPP_
#define TARGETBUMPER_HPP_

#include "Armor.hpp"
#include <string>

namespace xz_rm
{
#define MAX_LOSS_BUMP_COUNT 25  // 连续25帧未检测到目标则为丢失目标
#define MAX_DETECT_BUMP_COUNT 5 // 连续5帧检测到其他目标则为获取目标

    enum TARGET_MODE
    {
        NOT_GET_TARGET = 0,       // 未获取目标
        CONTINOUS_GET_TARGET = 1, // 连续获取目标
        LOST_BUMP = 2,            // 缓冲阶段
        DETECT_BUMP = 3           // 进入连续识别的缓冲
    };
    class TargetBumper
    {
    private:
        int target_loss_count = 0; // 目标丢失计数
        const string target_mode_str[4] = {"NOT_GET_TARGET", "CONTINOUS_GET_TARGET", "LOST_BUMP", "DETECT_BUMP"};

        static float getDistance2Center(const Armor &armor);
        static bool comfunc(const Armor &armor1, const Armor &armor2);
        void getTargetOrder(Armor &armors);

    public:
        TargetBumper();
        bool LossAndCheck(int mode);
        void TargetLossEmpty();
    };
};

#endif