/* Callback para salir al presionar Home */
int exit_callback(int arg1, int arg2, void *common) {
          sceKernelExitGame();
          return 0;
}

/* Hilo de Callback*/
int CallbackThread(SceSize args, void *argp) {
          int cbid;
          cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
          sceKernelRegisterExitCallback(cbid);
          sceKernelSleepThreadCB();
          return 0;
}

/* Establece el hilo de Callback y retorna su identificador */
int SetupCallbacks(void) {
          int thid = 0;
          thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
          if(thid >= 0) sceKernelStartThread(thid, 0, 0);
          return thid;
}
