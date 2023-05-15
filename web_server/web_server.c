#include <stdio.h>

#include <system_server.h>
#include <gui.h>
#include <input.h>
#include <web_server.h>

int create_web_server()
{
    pid_t systemPid;

    printf("여기서 Web Server 프로세스를 생성합니다.\n");

    /* fork + exec 를 이용하세요 */
    systemPid = fork();
    switch(systemPid)
    {
        case -1:
            printf("Fork failded in system_server!");
            break;
        
        case 0: // Child process
            printf("My process pid is : %d | parent pid is %d\n", systemPid, getppid());
            execl("/usr/local/bin/filebrowser", "filebrowser", "-p", "8282", (char *) NULL);
            break;

        default:
            printf("Parent process pid is %d\n", systemPid);
    }
    /* exec으로 filebrowser을 실행 하세요. */
    /* execl("/usr/local/bin/filebrowser", "filebrowser", "-p", "8282", (char *) NULL)) */

    return 0;
}
