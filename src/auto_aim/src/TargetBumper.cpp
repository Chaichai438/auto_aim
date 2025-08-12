#include "../include/TargetBumper.hpp"

namespace xz_rm
{
    float TargetBumper::getDistance2Center(const Armor &armor)
    {
        const cv::Point2f center_point = cv::Point2f(640, 512); // 假设传进来的图像为1280x512
        cv::Point2f armor_center = cv::Point2f(armor.width / 2.0, (armor.left_lightbar.length + armor.right_lightbar.length) / 2);
        cv::Point2f diff = armor_center - center_point;
        return diff.x * diff.x + diff.y + diff.y;
    }

    bool TargetBumper::LossAndCheck(int mode)
    {
        if (mode == LOST_BUMP)
        {
            target_loss_count++;
            if (target_loss_count >= MAX_LOSS_BUMP_COUNT)
            {
                TargetLossEmpty();
                return false;
            }
            return true;
        }

        else if (mode == DETECT_BUMP)
        {
            target_loss_count++;
            if (target_loss_count >= MAX_DETECT_BUMP_COUNT)
            {
                TargetLossEmpty();
                return false;
            }
            return true;
        }
        return false;
    }

    void TargetBumper::TargetLossEmpty()
    {
        target_loss_count = 0;
    }
}
