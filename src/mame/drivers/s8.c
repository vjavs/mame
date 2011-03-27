/*
    Williams System 8
*/
#include "emu.h"
#include "cpu/m6800/m6800.h"

extern const char layout_pinball[];

class williams_s8_state : public driver_device
{
public:
	williams_s8_state(running_machine &machine, const driver_device_config_base &config)
		: driver_device(machine, config) { }
};


static ADDRESS_MAP_START( williams_s8_map, AS_PROGRAM, 8 )
	ADDRESS_MAP_UNMAP_HIGH
ADDRESS_MAP_END

static INPUT_PORTS_START( williams_s8 )
INPUT_PORTS_END

static MACHINE_RESET( williams_s8 )
{
}

static DRIVER_INIT( williams_s8 )
{
}

static MACHINE_CONFIG_START( williams_s8, williams_s8_state )
	/* basic machine hardware */
	MCFG_CPU_ADD("maincpu", M6800, 1000000)
	MCFG_CPU_PROGRAM_MAP(williams_s8_map)

	MCFG_MACHINE_RESET( williams_s8 )

	/* video hardware */
	MCFG_DEFAULT_LAYOUT(layout_pinball)
MACHINE_CONFIG_END

/*--------------------
/ Pennant Fever (#526)
/--------------------*/
ROM_START(pfevr_l2)
	ROM_REGION(0x10000, "maincpu", 0)
	ROM_LOAD("pf-rom1.u19", 0x5000, 0x1000, CRC(00be42bd) SHA1(72ca21c96e3ffa3c43499165f3339b669c8e94a5))
	ROM_RELOAD( 0xd000, 0x1000)
	ROM_LOAD("pf-rom2.u20", 0x6000, 0x2000, CRC(7b101534) SHA1(21e886d5872104d71bb528b9affb12230268597a))
	ROM_RELOAD( 0xe000, 0x2000)
	ROM_REGION(0x10000, "cpu2", 0)
	ROM_LOAD("cpu_u49.128", 0xc000, 0x4000, CRC(b0161712) SHA1(5850f1f1f11e3ac9b9629cff2b26c4ad32436b55))
	ROM_RELOAD(0x8000, 0x4000)
ROM_END

ROM_START(pfevr_p3)
	ROM_REGION(0x10000, "maincpu", 0)
	ROM_LOAD("cpu_u19.732", 0x5000, 0x1000, CRC(03796c6d) SHA1(38c95fcce9d0f357a74f041f0df006b9c6f6efc7))
	ROM_RELOAD( 0xd000, 0x1000)
	ROM_LOAD("cpu_u20.764", 0x6000, 0x2000, CRC(3a3acb39) SHA1(7844cc30a9486f718a556850fc9cef3be82f26b7))
	ROM_RELOAD( 0xe000, 0x2000)
	ROM_REGION(0x10000, "cpu2", 0)
	ROM_LOAD("cpu_u49.128", 0xc000, 0x4000, CRC(b0161712) SHA1(5850f1f1f11e3ac9b9629cff2b26c4ad32436b55))
	ROM_RELOAD(0x8000, 0x4000)
ROM_END

GAME(1984,	pfevr_l2,		0,			williams_s8,	williams_s8,	williams_s8,	ROT0,	"Williams",		"Pennant Fever Baseball (L-2)",	GAME_NOT_WORKING | GAME_NO_SOUND | GAME_MECHANICAL)
GAME(1984,	pfevr_p3,		pfevr_l2,	williams_s8,	williams_s8,	williams_s8,	ROT0,	"Williams",		"Pennant Fever Baseball (P-3)",	GAME_NOT_WORKING | GAME_NO_SOUND | GAME_MECHANICAL)
