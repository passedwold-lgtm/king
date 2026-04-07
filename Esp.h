#pragma once
#include <stdint.h>

// 🔥 FIX ALL
#define ENCRYPTOFFSET(x) x
#define nssoxorany(x) @(x)

static inline uintptr_t getRealOffset(const char* offset) {
    return strtoull(offset, 0, 16);
}

// ICON FIX
#define ICON_FA_CROSSHAIRS ""
#define ICON_FA_EYE ""
#define ICON_FA_COGS ""
#define ICON_FA_ADDRESS_CARD ""

// GAME FUNC FIX
#define get_isLocalTeam(x) false
#define get_IsDieing(x) false
#define get_isVisible(x) true
#define get_MaxHP(x) 100
#define IsPlayerDead(x) false
// แล้วค่อย include
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

// --- Vector3 Definition ---
struct Vector3 {
    float x, y, z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}
    static Vector3 zero() { return Vector3(0, 0, 0); }
    
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(float f) const { return Vector3(x * f, y * f, z * f); }
};

struct Quaternion {
    float x, y, z, w;
    static Quaternion LookRotation(Vector3 forward, Vector3 up) { return Quaternion(); }
};

// --- Math Utilities ---
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define RAD2DEG( x )  ( (float)(x) * (float)(180.f / M_PI) )
#define DEG2RAD( x ) ( (float)(x) * (float)(M_PI / 180.f) )

// à¹à¸à¸¥à¸µà¹à¸¢à¸à¸à¸·à¹à¸­ clamp à¹à¸à¹à¸ _clamp à¹à¸à¸·à¹à¸­à¹à¸¡à¹à¹à¸«à¹à¸à¸à¸à¸±à¸ std::clamp
template <typename T>
inline T _clamp(const T& n, const T& lower, const T& upper) {
  return std::max(lower, std::min(n, upper));
}

inline float lerp(float a, float b, float f) {
    return _clamp<float>(a + f * (b - a), a > b ? b : a, a > b ? a : b);
}

// --- ImGui Operators ---
static inline ImVec2  operator*(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x * rhs, lhs.y * rhs); }
static inline ImVec2  operator/(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x / rhs, lhs.y / rhs); }
static inline ImVec2  operator+(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x + rhs, lhs.y + rhs); }
static inline ImVec2  operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
static inline ImVec2  operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
static inline ImVec2  operator-(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x - rhs, lhs.y - rhs); }
static inline ImVec2  operator*(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x * rhs.x, lhs.y * rhs.y); }
static inline ImVec2  operator/(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x / rhs.x, lhs.y / rhs.y); }
static inline ImVec2& operator*=(ImVec2& lhs, const float rhs) { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
static inline ImVec2& operator/=(ImVec2& lhs, const float rhs) { lhs.x /= rhs; lhs.y /= rhs; return lhs; }
static inline ImVec2& operator+=(ImVec2& lhs, const ImVec2& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
static inline ImVec2& operator-=(ImVec2& lhs, const ImVec2& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }
static inline ImVec2& operator*=(ImVec2& lhs, const ImVec2& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; return lhs; }
static inline ImVec2& operator/=(ImVec2& lhs, const ImVec2& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; return lhs; }
static inline ImVec4  operator+(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w); }
static inline ImVec4  operator-(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w); }
static inline ImVec4  operator*(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w); }

// --- ESP Functions ---
#define ARGB(a, r, g, b) 0 | a << 24 | r << 16 | g << 8 | b

float Rainbow() {
    static float x = 0, y = 0;
    static float r = 0, g = 0, b = 0;
    if (y >= 0.0f && y < 255.0f) {
        r = 255.0f; g = 0.0f; b = x;
    } else if (y >= 255.0f && y < 510.0f) {
        r = 255.0f - x; g = 0.0f; b = 255.0f;
    } else if (y >= 510.0f && y < 765.0f) {
        r = 0.0f; g = x; b = 255.0f;
    } else if (y >= 765.0f && y < 1020.0f) {
        r = 0.0f; g = 255.0f; b = 255.0f - x;
    } else if (y >= 1020.0f && y < 1275.0f) {
        r = x; g = 255.0f; b = 0.0f;
    } else if (y >= 1275.0f && y < 1530.0f) {
        r = 255.0f; g = 255.0f - x; b = 0.0f;
    }
    x += 0.25f; if (x >= 255.0f) x = 0.0f;
    y += 0.25f; if (y > 1530.0f) y = 0.0f;
    return ARGB(255, (int)r, (int)g, (int)b);
}

ImColor GetHealthColor (float health, float maxHp = 100.0f) {
    float r = std::min(519 * (maxHp - health) / maxHp, 255.0f);
    float g = std::min(510 * health / maxHp, 255.0f); 
    return ImVec4(r/ 255.0f, g / 255.0f, 0.f, 1.0f);
}

bool isOutsideScreen(ImVec2 pos, ImVec2 screen) {
    return (pos.y < 0 || pos.x > screen.x || pos.y > screen.y || pos.x < 0);
}

Vector3 add(Vector3 v1, Vector3 v2) {
    return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

ImVec2 pushToScreenBorder(ImVec2 Pos, ImVec2 screen, int offset) {
    int x = (int) Pos.x;
    int y = (int) Pos.y;
    if (Pos.y < 0) y = -offset;
    if (Pos.x > screen.x) x = (int) screen.x + offset;
    if (Pos.y > screen.y) y = (int) screen.y + offset;
    if (Pos.x < 0) x = -offset;
    return ImVec2(x, y);
}

void DrawBox(float X, float Y, float W, float H, ImColor Color, float curve, float thickness) {
    ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    draw_list->AddRect(ImVec2(X + 1, Y + 1), ImVec2(((X + W) - 1), ((Y + H) - 1)), Color);
    draw_list->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), Color, curve, thickness);
}

void drawRectFilledWithPos(ImVec2 pos, ImVec2 size, ImColor color) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y), color, 0, 0);
}

void DrawText2(ImFont * _espFont, float fontSize, ImVec2 position, ImColor Color, const char *text, ImColor colorFilled) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(position.x-3,position.y-3), ImVec2(position.x + _espFont->CalcTextSizeA(fontSize, MAXFLOAT, 0.0f, text).x + 3, position.y + 12), colorFilled, 0, 0);
    ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    draw_list->AddText(NULL, fontSize, position, Color, text);
}

void hpasddsfhjdjhsbsd(float hp, float maxHp, float xh, float yh) {
    float rate = 1.0f * hp/ maxHp;
    float width = 50; float height = 4;
    float x = xh - width * 0.5; float y = yh - height;
    ImColor color = ImColor(0,255,0);
    if (rate < 0.35) color = ImColor(255,0,0);
    else if (rate < 0.75) color = ImColor(255,165,0);
    drawRectFilledWithPos(ImVec2(x, y), ImVec2(width * rate, height), color);
}

void RenderLine(const ImVec2& from, const ImVec2& to, ImColor Color, float thickness) {
    ImGui::GetForegroundDrawList()->AddLine(from, to, Color, thickness);
}

// --- Global Variables ---
bool ESPEnable, ESPLine, ESPBox, ESPHealth, ESPDistance, ESPName, ESPArrow, Crosshair;
bool AIMKKILL, NINJARUN, AI_PLAYER, FLYJUMP, AUTOFLY, FLYV2, STOP, MOVE, XMOVE, AIMKILL_0s;
void (*_NinjaRun)(void* player, bool enable);
void (*_FlyJump)(void* player, bool enable);
void (*_AutoFly)(void* player, bool enable);
void (*_Move)(void* player, float x, float y, float z);
void (*_Stop)(void* player);
void (*_AimKill0s)(void* player, void* target);
float colorEsp[3] = {255, 255, 255};
static int Box = 0;
float AimFov = 0.0f;
bool aimStart, isAimFov, AimScope, AimFire, AimDam, LuonluomAim, line, FSWitch, AimVisible;
static bool AimKill = false;
static int style_idx = 0;
static int AimWhen = 1;
static int AimType = 0;
static bool autotroca = false;
static bool sID = false;
static int tS = 0;
bool enable_circleFov = false;
int circleSizeValue = 40;
int aim_target = 0;

bool (*Team) (void*player);
int (*maxhealth)(void *player);
void* (*get_camera)();
void* (*get_transform)(void*);
Vector3 (*worldToScreen)(void *cam, Vector3 pos);
Vector3 (*WorldToViewpoint)(void*, Vector3, int);
Vector3 (*get_position)(void*);
ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

// --- Classes ---
class Vvector3 {
public:
    float x, y, z;
    Vvector3() : x(0), y(0), z(0) {}
    Vvector3(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}
};

Vector3 getPosition(void *transform) {
    return get_position(get_transform(transform));
} 

bool FastReload1 = true;
float FastReload(void *instance) { return 31.0; }

bool K02 = true;
float Speed(void *instance) { return K02 ? 2.7 : 2.0; }

Vector3 GetPlayerLocation(void* player) {
    return get_position(get_transform(player));
}

void *(*get_transformFF)(void*inst);

static void *CurentMatch() {
    void *(*_CurentMatch) (void *instance) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1025F11F0")); 
    return _CurentMatch(NULL);
}

static Vector3 Transform_GetPosition(void *player) {
    Vector3 out = Vector3::zero();
    void (*_Transform_GetPosition)(void *transform, Vector3 * out) = (void (*)(void *, Vector3 *))getRealOffset(ENCRYPTOFFSET("0x1063ABA4C"));
    _Transform_GetPosition(player, &out);
    return out;
}

static Vector3 Transform_INTERNAL_GetPosition(void *player) {
    Vector3 out = Vector3::zero();
    void (*_Transform_INTERNAL_GetPosition)(void *transform, Vector3 * out) = (void (*)(void *, Vector3 *))getRealOffset(ENCRYPTOFFSET("0x1063ABA4C"));
    _Transform_INTERNAL_GetPosition(player, &out);
    return out;
}

static void Transform_INTERNAL_SetPosition(void *player, Vvector3 inn) {
    void (*_Transform_INTERNAL_SetPosition)(void *transform, Vvector3 in) = (void (*)(void *, Vvector3))getRealOffset(ENCRYPTOFFSET("0x1063ABAF0"));
    _Transform_INTERNAL_SetPosition(player, inn);
}

bool IsClientBot(void* _this) { return *(bool*)((uint64_t)_this + 0x2F8); }

static void *GetLocalPlayer(void* Match) {
    void *(*_GetLoalPlayer)(void *match) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x104871C9C")); 
    return _GetLoalPlayer(Match);
}

static void *Current_Local_Player() {
    void *(*_Local_Player)(void *players) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1025F16C0"));
    return _Local_Player(NULL);
}

static void *GetLocalPlayerOrObServer() {
    void *(*_GetLocalPlayerOrObServer)(void *players) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1025F1DBC"));
    return _GetLocalPlayerOrObServer(NULL);
}

Vector3 GetHeadPosition(void* player) {
    void *HeadITF= *(void **)((uintptr_t) player + 0x4D0);
    void *HeadTF = get_transformFF(HeadITF);
    return getPosition(HeadTF);
}

static void *Camera_main() {
    void *(*_Camera_main)(void *nuls) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x106364C78"));
    return _Camera_main(nullptr);
}

// --- World to Screen ---
ImVec2 world2screen_i(Vector3 pos) {
    auto cam = get_camera();
    if (!cam) return {0,0};
    Vector3 worldPoint = WorldToViewpoint(cam, pos, 2);
    int ScreenWidth = ImGui::GetIO().DisplaySize.x;
    int ScreenHeight = ImGui::GetIO().DisplaySize.y;
    return {ScreenWidth * worldPoint.x, ScreenHeight - worldPoint.y * ScreenHeight};
}

ImVec2 world2screen_c(Vector3 pos, bool &checker) {
    auto cam = get_camera();
    if (!cam) return {0,0};
    Vector3 worldPoint = WorldToViewpoint(cam, pos, 2);
    int ScreenWidth = ImGui::GetIO().DisplaySize.x;
    int ScreenHeight = ImGui::GetIO().DisplaySize.y;
    checker = worldPoint.z > 1;
    return {ScreenWidth * worldPoint.x, ScreenHeight - worldPoint.y * ScreenHeight};
}

Quaternion GetRotationToLocation(Vector3 targetLocation, float y_bias, Vector3 myLoc){
    return Quaternion::LookRotation((targetLocation + Vector3(0, y_bias, 0)) - myLoc, Vector3(0, 1, 0));
}

// --- Main Draw Function ---
void DrawEsp() {
    if (Crosshair) {
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        float size = ImGui::GetMainViewport()->Size.x * 0.03f;
        float halfSize = size * 0.5f;
        ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x - halfSize, center.y), ImVec2(center.x + halfSize, center.y), IM_COL32(255, 255, 255, 255));
        ImGui::GetBackgroundDrawList()->AddLine(ImVec2(center.x, center.y - halfSize), ImVec2(center.x, center.y + halfSize), IM_COL32(255, 255, 255, 255));
    }
    
    if (ESPEnable) {
        void *current_Match = CurentMatch();
        void *local_player = GetLocalPlayer(current_Match);
        // ... [à¸ªà¹à¸§à¸à¸à¸µà¹à¹à¸«à¸¥à¸·à¸­à¸à¸­à¸à¸à¸±à¸à¸à¹à¸à¸±à¸ DrawEsp à¸ªà¸²à¸¡à¸²à¸£à¸à¹à¸ªà¹à¸à¹à¸­à¸à¸²à¸à¸à¸µà¹à¹à¸à¹à¹à¸¥à¸¢à¸à¸£à¸±à¸] ...
    }
}
