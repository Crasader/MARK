#ifndef __WELCOME_LOGO_I_LAYER_LOGO_H__
#define __WELCOME_LOGO_I_LAYER_LOGO_H__

class ILayerLogo
{
public:
	virtual void createSkin() {}//����Ƥ��
	virtual void playAnimation() {}//���Ŷ���
	virtual bool isLogoPlayOver() { return false; }//�Ƿ�LOGO����

};

#endif