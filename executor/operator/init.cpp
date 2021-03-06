namespace TEngine {

extern void NodeOpsRegistryManagerInit(void);
extern void RegisterCommonOps(void);
extern void RegisterRefOps(void);

#if CONFIG_ARCH_ARM64 == 1 || CONFIG_ARCH_ARM32 == 1
extern void RegisterArmOps(void);
#endif

#if CONFIG_ARCH_ARM8_2 == 1
extern void RegisterArmHalfOps(void);
#endif
}    // namespace TEngine

using namespace TEngine;

extern "C" int register_hclcpu_ops(void)
{
    RegisterCommonOps();
    RegisterRefOps();

#if CONFIG_ARCH_ARM64 || CONFIG_ARCH_ARM32
    RegisterArmOps();
#endif

#if CONFIG_ARCH_ARM8_2
    RegisterArmHalfOps();
#endif

    return 0;

}
