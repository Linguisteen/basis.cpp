#pragma once // 确保只被 include 一次

#include <gydm/bang.hpp>

// 以 Linguisteen 的名义提供
namespace Linguisteen {
    // 创建自定义数据类型，并命名为 PaddleBallWorld, 继承自 TheBigBang
    class PaddleBallWorld : public GYDM::TheBigBang {
    public:
        PaddleBallWorld() : TheBigBang("托球游戏") {}

    public:    // 覆盖游戏基本方法
        void load(float width, float height) override;
        void update(uint64_t interval, uint32_t count, uint64_t uptime) override;

    protected:
        void on_mission_start(float width, float height) override;

    protected: // 覆盖键盘事件处理方法
        void on_char(char key, uint16_t modifiers, uint8_t repeats, bool pressed) override;

    private:   // 本游戏世界中的物体
        GYDM::IShapelet* ball;
        GYDM::IShapelet* paddle;
    };
}
