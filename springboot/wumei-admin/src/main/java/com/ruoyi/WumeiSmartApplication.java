package com.ruoyi;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.jdbc.DataSourceAutoConfiguration;
import org.springframework.core.annotation.Order;

/**
 * 启动程序
 * 
 * @author ruoyi
 */
@SpringBootApplication(exclude = { DataSourceAutoConfiguration.class })
public class WumeiSmartApplication
{
    public static void main(String[] args)
    {
        // System.setProperty("spring.devtools.restart.enabled", "false");
        SpringApplication.run(WumeiSmartApplication.class, args);
        System.out.println(
                "  ____   _____ _______ \n" +
                        " / __ \\ / ____|__   __|\n" +
                        "| |  | | (___    | |   \n" +
                        "| |  | |\\___ \\   | |   \n" +
                        "| |__| |____) |  | |   \n" +
                        " \\____/|_____/   |_|   \n"
        );
        System.out.println(
                " ---------操作系统课设——Iot项目---------\n" +
                        " =========分布式监测平台启动成功=========\n"
        );

    }
}
