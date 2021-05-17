#ifndef KernelExport_h__
#define KernelExport_h__


#if defined(WIN32)

#ifdef IxKernel_EXPORTS
#define KERNEL_EXPORT __declspec(dllexport)
#else
#define  KERNEL_EXPORT __declspec(dllimport)
#endif

#elif __linux__
#define KERNEL_EXPORT

#else
#define KERNEL_EXPORT 
#endif

#endif // KernelExport_h__
