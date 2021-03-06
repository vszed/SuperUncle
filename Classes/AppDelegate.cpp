#include "AppDelegate.h"
#include "LogoScene.h"
#include "TestScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
			glview = GLViewImpl::createWithRect("Super Uncle  V1.0", Rect(0, 0, 1272, 720)); //win32
		else
			glview = GLViewImpl::createWithRect("Super Uncle  V1.0", Rect(0, 0, 1234, 750)); //ios、Android平台

		director->setOpenGLView(glview);
	}

	if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		director->getOpenGLView()->setDesignResolutionSize(1272, 720, ResolutionPolicy::SHOW_ALL);//win32平台
	else
		director->getOpenGLView()->setDesignResolutionSize(1272, 720, ResolutionPolicy::NO_BORDER);//无边框 => ios、Android平台


	// turn on display FPS
	director->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);

	FileUtils::getInstance()->addSearchPath("res");

	// create a scene. it's an autorelease object
	auto scene = TestScene::createScene();

	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
