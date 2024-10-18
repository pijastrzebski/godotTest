#include "godotregistertypes.hpp"

#include "bullet.hpp"
#include "bunker.hpp"
#include "godotcustomanimatedsprite.hpp"
#include "godotcustombutton.hpp"
#include "godotcustomcharacterbody.hpp"
#include "godotcustomcontrol.hpp"
#include "godotcustomsprite.hpp"
#include "godotcustomtext.hpp"

#include "exitbutton.hpp"
#include "game.hpp"
#include "machinegun.hpp"
#include "main.hpp"
#include "menu.hpp"
#include "options.hpp"
#include "optionsbutton.hpp"
#include "startbutton.hpp"
#include "title.hpp"

extern "C" {
	GDExtensionBool GDE_EXPORT godotTestLibInit(GDExtensionInterfaceGetProcAddress procAddress, const GDExtensionClassLibraryPtr libraryPtr, GDExtensionInitialization* initializationPtr)
	{
		GDExtensionBinding::InitObject initObject(procAddress, libraryPtr, initializationPtr);

		initObject.register_initializer(GodotRegisterTypes::initializeTestLibModule);
		initObject.register_terminator(GodotRegisterTypes::uninitializeTestLibModule);
		initObject.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return initObject.init();
	}
}

void GodotRegisterTypes::initializeTestLibModule(ModuleInitializationLevel level)
{
	if (level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		std::cerr << "The level is not correct";
		return;
	}

	GDREGISTER_CLASS(GodotCustomSprite)
	GDREGISTER_CLASS(GodotCustomAnimatedSprite)
	GDREGISTER_CLASS(GodotCustomCharacterBody)
	GDREGISTER_CLASS(GodotCustomControl)
	GDREGISTER_CLASS(GodotCustomText)
	GDREGISTER_CLASS(GodotCustomButton)

	GDREGISTER_CLASS(Main)
	GDREGISTER_CLASS(Game)
	GDREGISTER_CLASS(Menu)
	GDREGISTER_CLASS(Title)
	GDREGISTER_CLASS(Options)
	GDREGISTER_CLASS(OptionsButton)
	GDREGISTER_CLASS(StartButton)
	GDREGISTER_CLASS(ExitButton)

	GDREGISTER_CLASS(Bunker)
	GDREGISTER_CLASS(MachineGun)
	GDREGISTER_CLASS(Bullet)

}

void GodotRegisterTypes::uninitializeTestLibModule(ModuleInitializationLevel level)
{
	if (level != MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		std::cerr << "The level is not correct";
		return;
	}
}
