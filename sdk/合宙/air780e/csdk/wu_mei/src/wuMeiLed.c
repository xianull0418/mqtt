#include "wuMeiLed.h"


#define LED0_PIN HAL_GPIO_26
void ledInit()
{
	luat_gpio_cfg_t gpioCfg; //�����ṹ��
	luat_gpio_set_default_cfg(&gpioCfg); //��ʼ���ṹ��
	gpioCfg.pull = LUAT_GPIO_PULLDOWN; //�ⲿ������������ ����Ҳ���ó�����
	gpioCfg.mode = LUAT_GPIO_OUTPUT;
	gpioCfg.output_level = LUAT_GPIO_LOW;

	gpioCfg.pin = LED0_PIN;
	luat_gpio_open(&gpioCfg); //��
	luat_gpio_set(gpioCfg.pin, 0); //����͵�ƽ
}

unsigned char ledControl(unsigned char nledIndex, unsigned char nValue)
{
	if (nValue == 0)
		luat_gpio_set(LED0_PIN, 0);
	else
		luat_gpio_set(LED0_PIN, 1);
	return 1; //Ĭ�϶��ɹ�
}