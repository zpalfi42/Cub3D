#include <stdio.h>
#include "mlx.h"

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1);
    win_ptr = mlx_new_window(mlx_ptr, 1280, 1024, "Cub3D");
    mlx_loop(mlx_ptr);
}