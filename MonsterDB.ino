MonsterDB::MonsterDB(){

  oceanTrue = true;
  oceanFalse = false;

	monsterRepo[Digiegg] =       
		MonsterRef(
			Digiegg,
			digiegg1,digiegg2,digiegg3,
			EGG,
			EGG_STAGE,
			oceanFalse,
			MonsterList(Botamon,Poyomon)
		);

	monsterRepo[Grave] =
		MonsterRef(
			Grave,
			grave1,grave2,grave1,
			SITTER,
			DEATH_STAGE,
			oceanFalse,
			MonsterList(Digiegg,Tamaegg,Oceanegg,Obaketchi)
		);

	monsterRepo[Poop] =           
		MonsterRef(
			Poop,
			poop1,poop2,poop1, 
			SITTER,
			POOP_STAGE,
			oceanFalse, 
			MonsterList(Poop)
		);
		
	//START NEW
	monsterRepo[Agumon] = 
	MonsterRef(
		Agumon,
		agumon1,agumon2,agumon3,
		MOVER,
		TEEN_STAGE,
		oceanFalse,
		MonsterList(Greymon,Tyranomon,Growlmon)
	);
	monsterRepo[Andiramon] = 
		MonsterRef(
			Andiramon,
			andiramon1,andiramon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Cherubimon,Cherubimon)
		);
	monsterRepo[Andromon] = 
		MonsterRef(
			Andromon,
			andromon1,andromon2,andromon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe,Mugendramon)
		);
	monsterRepo[Androtchi] = 
		MonsterRef(
			Androtchi,
			androtchi1,androtchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Angemon] = 
		MonsterRef(
			Angemon,
			angemon1,angemon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Holyangemon,Holyangemon,Vamdemon)
		);
	monsterRepo[Angewomon] = 
		MonsterRef(
			Angewomon,
			angewomon1,angewomon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Ashigyotchi] = 
		MonsterRef(
			Ashigyotchi,
			ashigyotchi1,ashigyotchi2,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Atlurkabuterimon] = 
		MonsterRef(
			Atlurkabuterimon,
			atlurkabuterimon1,atlurkabuterimon2,atlurkabuterimon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Babytchi] = 
		MonsterRef(
			Babytchi,
			babytchi1,babytchi2,
			MOVER,
			BABY_STAGE,
			oceanFalse,
			MonsterList(Tonmarutchi,Mohitamatchi,Hyurutchi)
		);
	monsterRepo[Bakemon] = 
		MonsterRef(
			Bakemon,
			bakemon1,bakemon2,bakemon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Phantomon,Vamdemon,Pumpmon)
		);
	monsterRepo[Betamon] = 
		MonsterRef(
			Betamon,
			betamon1,betamon2,
			MOVER,
			TEEN_STAGE,
			oceanTrue,
			MonsterList(Shellmon,Seadramon,Ikkakumon,Gesomon)
		);
	monsterRepo[Bill] = 
		MonsterRef(
			Bill,
			bill1,bill2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Botamon] = 
		MonsterRef(
			Botamon,
			botamon1,botamon2,botamon3,
			MOVER,
			BABY_STAGE,
			oceanFalse,
			MonsterList(Koromon,Tsunomon)
		);
	monsterRepo[Bunbuntchi] = 
		MonsterRef(
			Bunbuntchi,
			bunbuntchi1,bunbuntchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Cherubimon] = 
		MonsterRef(
			Cherubimon,
			cherubimon1,cherubimon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Debirudori] = 
		MonsterRef(
			Debirudori,
			debirudori1,debirudori2,debirudori3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Kingdeviltchi,Ship)
		);
	monsterRepo[Debirukotchi] = 
		MonsterRef(
			Debirukotchi,
			debirukotchi1,debirukotchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Futagodebiru,Ship)
		);
	monsterRepo[Debirumametchi] = 
		MonsterRef(
			Debirumametchi,
			debirumametchi1,debirumametchi2,debirumametchi3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Ship,Kuridebitchi)
		);
	monsterRepo[Demon] = 
		MonsterRef(
			Demon,
			demon1,demon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Deviltchi] = 
		MonsterRef(
			Deviltchi,
			deviltchi1,deviltchi2,deviltchi3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Pukudebitchi,Ghostdeviltchi)
		);
	monsterRepo[Devimon] = 
		MonsterRef(
			Devimon,
			devimon1,devimon2,devimon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Vamdemon,Etemon,Andiramon)
		);
	monsterRepo[Digitamamon] = 
		MonsterRef(
			Digitamamon,
			digitamamon1,digitamamon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Dolphmon] = 
		MonsterRef(
			Dolphmon,
			dolphmon1,dolphmon2,dolphmon3,
			FLOATER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Whamon,Megaseadramon)
		);
	monsterRepo[Dorotchi] = 
		MonsterRef(
			Dorotchi,
			dorotchi1,dorotchi2,dorotchi3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Drimogemon] = 
		MonsterRef(
			Drimogemon,
			drimogemon1,drimogemon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Monzaemon,Mainframe)
		);
	monsterRepo[Dukemon] = 
		MonsterRef(
			Dukemon,
			dukemon1,dukemon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Elecmon] = 
		MonsterRef(
			Elecmon,
			elecmon1,elecmon2,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Drimogemon,Leomon,Meramon)
		);
	monsterRepo[Etemon] = 
		MonsterRef(
			Etemon,
			etemon1,etemon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Extyranomon] = 
		MonsterRef(
			Extyranomon,
			extyranomon1,extyranomon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Flymon] = 
		MonsterRef(
			Flymon,
			flymon1,flymon2,flymon3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Piximon,Phantomon,Monzaemon)
		);
	monsterRepo[Frigimon] = 
		MonsterRef(
			Frigimon,
			frigimon1,frigimon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Monzaemon,Mainframe)
		);
	monsterRepo[Futagodebiru] = 
		MonsterRef(
			Futagodebiru,
			futagodebiru1,futagodebiru2,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship)
		);
	monsterRepo[Futagotenshi] = 
		MonsterRef(
			Futagotenshi,
			futagotenshi1,futagotenshi2,futagotenshi3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship)
		);
	monsterRepo[Gabumon] = 
		MonsterRef(
			Gabumon,
			gabumon1,gabumon2,gabumon3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Garurumon,Garurumon,Mojyamon)
		);
	monsterRepo[Garurumon] = 
		MonsterRef(
			Garurumon,
			garurumon1,garurumon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Weregarurumon,Weregarurumon,Mamemon)
		);
	monsterRepo[Gesomon] = 
		MonsterRef(
			Gesomon,
			gesomon1,gesomon2,gesomon3,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Whamon,Megaseadramon)
		);
	monsterRepo[Ghostdeviltchi] = 
		MonsterRef(
			Ghostdeviltchi,
			ghostdeviltchi1,ghostdeviltchi2,ghostdeviltchi3,
			FLOATER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Debirudori,Kabodebitchi)
		);
	monsterRepo[Ginjirotchi] = 
		MonsterRef(
			Ginjirotchi,
			ginjirotchi1,ginjirotchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Ginjirotenshi] = 
		MonsterRef(
			Ginjirotenshi,
			ginjirotenshi1,ginjirotenshi2,ginjirotenshi3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship)
		);
	monsterRepo[Giromon] = 
		MonsterRef(
			Giromon,
			giromon1,giromon2,giromon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Gizamon] = 
		MonsterRef(
			Gizamon,
			gizamon1,gizamon2,gizamon3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Sukamon,Leomon,Ogremon)
		);
	monsterRepo[Gomamon] = 
		MonsterRef(
			Gomamon,
			gomamon1,gomamon2,
			MOVER,
			TEEN_STAGE,
			oceanTrue,
			MonsterList(Ikkakumon,Dolphmon,Shellmon)
		);
	monsterRepo[Gozarutchi] = 
		MonsterRef(
			Gozarutchi,
			gozarutchi1,gozarutchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Greymon] = 
		MonsterRef(
			Greymon,
			greymon1,greymon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Metalgreymon,Metalgreymon,Mamemon)
		);
	monsterRepo[Growlmon] = 
		MonsterRef(
			Growlmon,
			growlmon1,growlmon2,growlmon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Giromon,Megalogrowlmon,Megalogrowlmon)
		);
	monsterRepo[Guilmon] = 
		MonsterRef(
			Guilmon,
			guilmon1,guilmon2,guilmon3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Growlmon,Growlmon,Tyranomon)
		);
	monsterRepo[Hanatchi] = 
		MonsterRef(
			Hanatchi,
			hanatchi1,hanatchi2,hanatchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Hashitamatchi] = 
		MonsterRef(
			Hashitamatchi,
			hashitamatchi1,hashitamatchi2,hashitamatchi3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Hashizotchi,Kusatchi,Tarakotchi)
		);
	monsterRepo[Hashizotchi] = 
		MonsterRef(
			Hashizotchi,
			hashizotchi1,hashizotchi2,hashizotchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Hikotchi] = 
		MonsterRef(
			Hikotchi,
			hikotchi1,hikotchi2,
			FLOATER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Androtchi,Takotchi,Kuchipatchi,Hiratchi)
		);
	monsterRepo[Hinotamatchi] = 
		MonsterRef(
			Hinotamatchi,
			hinotamatchi1,hinotamatchi2,hinotamatchi3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Gozarutchi,Masukutchi,Hanatchi)
		);
	monsterRepo[Hiratchi] = 
		MonsterRef(
			Hiratchi,
			hiratchi1,hiratchi2,hiratchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Grave,Ship)
		);
	monsterRepo[Holyangemon] = 
		MonsterRef(
			Holyangemon,
			holyangemon1,holyangemon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Seraphimon,Seraphimon,Seraphimon,Mainframe)
			
		);
	monsterRepo[Hyurutchi] = 
		MonsterRef(
			Hyurutchi,
			hyurutchi1,hyurutchi2,hyurutchi3,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Hashitamatchi,Hinotamatchi,Propellertchi)
		);
	monsterRepo[Ichigotchi] = 
		MonsterRef(
			Ichigotchi,
			ichigotchi1,ichigotchi2,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Mametchi,Memetchi,Bunbuntchi,Wooltchi)
		);
	monsterRepo[Ikkakumon] = 
		MonsterRef(
			Ikkakumon,
			ikkakumon1,ikkakumon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Zudomon,Zudomon,Whamon,Megaseadramon)
		);
	monsterRepo[Kabodebitchi] = 
		MonsterRef(
			Kabodebitchi,
			kabodebitchi1,kabodebitchi2,kabodebitchi3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship)
		);
	monsterRepo[Kabuterimon] = 
		MonsterRef(
			Kabuterimon,
			kabuterimon1,kabuterimon2,kabuterimon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Andromon,Vademon,Atlurkabuterimon)
		);
	monsterRepo[Kaitchi] = 
		MonsterRef(
			Kaitchi,
			kaitchi1,kaitchi2,
			SHY_SITTER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Ningyotchi,Ship)
		);
	monsterRepo[Keropyontchi] = 
		MonsterRef(
			Keropyontchi,
			keropyontchi1,keropyontchi2,keropyontchi3,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Kinakomotchi] = 
		MonsterRef(
			Kinakomotchi,
			kinakomotchi1,kinakomotchi2,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Ichigotchi,Youngmimitchi,Ufotchi)
		);
	monsterRepo[Kingdeviltchi] = 
		MonsterRef(
			Kingdeviltchi,
			kingdeviltchi1,kingdeviltchi2,kingdeviltchi3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship)
		);
	monsterRepo[Kingyotchi] = 
		MonsterRef(
			Kingyotchi,
			kingyotchi1,kingyotchi2,
			FLOATER,
			TEEN_STAGE,
			oceanTrue,
			MonsterList(Taiyakitchi,Kaitchi,Kujiratchi,Ashigyotchi)
		);
	monsterRepo[Koromon] = 
		MonsterRef(
			Koromon,
			koromon1,koromon2,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Agumon,Betamon,Guilmon)
		);
	monsterRepo[Kotoden] = 
		MonsterRef(
			Kotoden,
			kotoden1,kotoden2,kotoden3,
			FLOATER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Kuriten,Ginjirotenshi)
		);
	monsterRepo[Kuchipatchi] = 
		MonsterRef(
			Kuchipatchi,
			kuchipatchi1,kuchipatchi2,kuchipatchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Kuchitamatchi] = 
		MonsterRef(
			Kuchitamatchi,
			kuchitamatchi1,kuchitamatchi2,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Ginjirotchi,Kuchipatchi,Nyorotchi,Takotchi)
		);
	monsterRepo[Kujiratchi] = 
		MonsterRef(
			Kujiratchi,
			kujiratchi1,kujiratchi2,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Kunemon] = 
		MonsterRef(
			Kunemon,
			kunemon1,kunemon2,kunemon3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Sukamon,Kuwagamon,Ogremon,Flymon)
		);
	monsterRepo[Kuragetchi] = 
		MonsterRef(
			Kuragetchi,
			kuragetchi1,kuragetchi2,
			FLOATER,
			CHILD_STAGE,
			oceanTrue,
			MonsterList(Kingyotchi,Otototchi)
		);
	monsterRepo[Kuridebitchi] = 
		MonsterRef(
			Kuridebitchi,
			kuridebitchi1,kuridebitchi2,kuridebitchi3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship)
		);
	monsterRepo[Kuriten] = 
		MonsterRef(
			Kuriten,
			kuriten1,kuriten2,kuriten3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Futagotenshi,Ship,Ship)
		);
	monsterRepo[Kusatchi] = 
		MonsterRef(
			Kusatchi,
			kusatchi1,kusatchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Kuwagamon] = 
		MonsterRef(
			Kuwagamon,
			kuwagamon1,kuwagamon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Vademon,Mamemon,Andromon) //REVISIT,
		);
	monsterRepo[Ladydevimon] = 
		MonsterRef(
			Ladydevimon,
			ladydevimon1,ladydevimon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Lillithmon,Lillithmon,Mainframe)
		);
	monsterRepo[Leomon] = 
		MonsterRef(
			Leomon,
			leomon1,leomon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Sabreleomon,Sabreleomon,Etemon,Piximon)
		);
	monsterRepo[Lillithmon] = 
		MonsterRef(
			Lillithmon,
			lillithmon1,lillithmon2,lillithmon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Mainframe] =
		MonsterRef(
			Mainframe,
			mainframe1,mainframe2,
			SITTER,
			DEATH_STAGE,
			oceanFalse,
			MonsterList(Digiegg,Tamaegg,Oceanegg)
		);
	monsterRepo[Mamemon] = 
		MonsterRef(
			Mamemon,
			mamemon1,mamemon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Mametchi] = 
		MonsterRef(
			Mametchi,
			mametchi1,mametchi2,mametchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Marutchi] = 
		MonsterRef(
			Marutchi,
			marutchi1,marutchi2,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Kuchitamatchi,Tamatchi,Youngmametchi,Propellertchi)
		);
	monsterRepo[Maruten] = 
		MonsterRef(
			Maruten,
			maruten1,maruten2,
			FLOATER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Kotoden,Takoten)
		);
	monsterRepo[Masktchi] = 
		MonsterRef(
			Masktchi,
			masktchi1,masktchi2,masktchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Zatchi,Ship,Grave)
		);
	monsterRepo[Masukutchi] = 
		MonsterRef(
			Masukutchi,
			masukutchi1,masukutchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Bill,Bill,Ship)
		);
	monsterRepo[Megadramon] = 
		MonsterRef(
			Megadramon,
			megadramon1,megadramon2,megadramon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Megalogrowlmon] = 
		MonsterRef(
			Megalogrowlmon,
			megalogrowlmon1,megalogrowlmon2,megalogrowlmon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Dukemon,Dukemon,Mugendramon)
		);
	monsterRepo[Megaseadramon] = 
		MonsterRef(
			Megaseadramon,
			megaseadramon1,megaseadramon2,megaseadramon3,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Metalseadramon,Metalseadramon,Metalpiranimon)
		);
	monsterRepo[Memetchi] = 
		MonsterRef(
			Memetchi,
			memetchi1,memetchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Meramon] = 
		MonsterRef(
			Meramon,
			meramon1,meramon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Andromon,Phantomon,Pumpmon)
		);
	monsterRepo[Metalgarurumon] = 
		MonsterRef(
			Metalgarurumon,
			metalgarurumon1,metalgarurumon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Omegamon,Omegamon,Mainframe)
		);
	monsterRepo[Metalgreymon] = 
		MonsterRef(
			Metalgreymon,
			metalgreymon1,metalgreymon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Wargreymon,Wargreymon,Mainframe)
		);
	monsterRepo[Metalpiranimon] = 
		MonsterRef(
			Metalpiranimon,
			metalpiranimon1,metalpiranimon2,metalpiranimon3,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Mainframe)
		);
	monsterRepo[Metalseadramon] = 
		MonsterRef(
			Metalseadramon,
			metalseadramon1,metalseadramon2,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Mainframe)
		);
	monsterRepo[Metaltyranomon] = 
		MonsterRef(
			Metaltyranomon,
			metaltyranomon1,metaltyranomon2,metaltyranomon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mugendramon,Mugendramon,Mainframe)
		);
	monsterRepo[Mimitchi] = 
		MonsterRef(
			Mimitchi,
			mimitchi1,mimitchi2,
			SITTER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Mochimon] = 
		MonsterRef(
			Mochimon,
			mochimon1,mochimon2,mochimon3,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Kunemon,Tentomon)
		);
	monsterRepo[Mohitamatchi] = 
		MonsterRef(
			Mohitamatchi,
			mohitamatchi1,mohitamatchi2,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Hinotamatchi,Oniontchi,Hikotchi)
		);
	monsterRepo[Mojyamon] = 
		MonsterRef(
			Mojyamon,
			mojyamon1,mojyamon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe,Piximon)//REVISIT,
		);
	monsterRepo[Monzaemon] = 
		MonsterRef(
			Monzaemon,
			monzaemon1,monzaemon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Mugendramon] = 
		MonsterRef(
			Mugendramon,
			mugendramon1,mugendramon2,mugendramon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Ningyotchi] = 
		MonsterRef(
			Ningyotchi,
			ningyotchi1,ningyotchi2,
			FLOATER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Numemon] = 
		MonsterRef(
			Numemon,
			numemon1,numemon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Extyranomon,Monzaemon,Vademon)
		);
	monsterRepo[Nyorotchi] = 
		MonsterRef(
			Nyorotchi,
			nyorotchi1,nyorotchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Obaketchi] = 
		MonsterRef(
			Obaketchi,
			obaketchi1,obaketchi2,
			MOVER,
			BABY_STAGE,
			oceanFalse,
			MonsterList(Maruten,Maruten,Deviltchi,Zukidebitchi)
		);
	monsterRepo[Oceanegg] = 
		MonsterRef(
			Oceanegg,
			oceanegg1,oceanegg2,
			SITTER,
			EGG_STAGE,
			oceanTrue,
			MonsterList(Planktontchi,Pitchmon)
		);
	monsterRepo[Ogremon] = 
		MonsterRef(
			Ogremon,
			ogremon1,ogremon2,ogremon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Digitamamon,Phantomon,Etemon,Giromon)
		);
	monsterRepo[Omegamon] = 
		MonsterRef(
			Omegamon,
			omegamon1,omegamon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Oniontchi] = 
		MonsterRef(
			Oniontchi,
			oniontchi1,oniontchi2,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Zuccitchi,Dorotchi,Hanatchi,Kusatchi)
		);
	monsterRepo[Otototchi] = 
		MonsterRef(
			Otototchi,
			otototchi1,otototchi2,
			FLOATER,
			TEEN_STAGE,
			oceanTrue,
			MonsterList(Keropyontchi,Taiyakitchi,Kujiratchi,Kaitchi)
		);
	monsterRepo[Oyajidebiru] = 
		MonsterRef(
			Oyajidebiru,
			oyajidebiru1,oyajidebiru2,
			FLOATER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Kabodebitchi,Debirukotchi)
		);
	monsterRepo[Patamon] = 
		MonsterRef(
			Patamon,
			patamon1,patamon2,patamon3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Angemon,Angemon,Leomon)
		);
	monsterRepo[Phantomon] = 
		MonsterRef(
			Phantomon,
			phantomon1,phantomon2,phantomon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Demon,Mainframe)
		);
	monsterRepo[Picodevimon] = 
		MonsterRef(
			Picodevimon,
			picodevimon1,picodevimon2,picodevimon3,
			FLOATER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Devimon,Bakemon,Meramon)
		);
	monsterRepo[Pitchmon] = 
		MonsterRef(
			Pitchmon,
			pitchmon1,pitchmon2,pitchmon3,
			FLOATER,
			BABY_STAGE,
			oceanTrue,
			MonsterList(Pukamon)
		);
	monsterRepo[Piximon] = 
		MonsterRef(
			Piximon,
			piximon1,piximon2,piximon3,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Planktontchi] = 
		MonsterRef(
			Planktontchi,
			planktontchi1,planktontchi2,
			FLOATER,
			BABY_STAGE,
			oceanTrue,
			MonsterList(Kuragetchi)
		);
	monsterRepo[Pochitchi] = 
		MonsterRef(
			Pochitchi,
			pochitchi1,pochitchi2,pochitchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Zatchi,Ship,Ship)
		);
	monsterRepo[Poyomon] = 
		MonsterRef(
			Poyomon,
			poyomon1,poyomon2,
			MOVER,
			BABY_STAGE,
			oceanFalse,
			MonsterList(Tokomon,Mochimon)
		);
	monsterRepo[Propellertchi] = 
		MonsterRef(
			Propellertchi,
			propellertchi1,propellertchi2,propellertchi3,
			FLOATER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Hiratchi,Nyorotchi,Masktchi)
		);
	monsterRepo[Pukamon] = 
		MonsterRef(
			Pukamon,
			pukamon1,pukamon2,pukamon3,
			FLOATER,
			CHILD_STAGE,
			oceanTrue,
			MonsterList(Gomamon,Shakomon,Gizamon)
		);
	monsterRepo[Pukudebitchi] = 
		MonsterRef(
			Pukudebitchi,
			pukudebitchi1,pukudebitchi2,pukudebitchi3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Debirumametchi,Debirudori)
		);
	monsterRepo[Pukuten] = 
		MonsterRef(
			Pukuten,
			pukuten1,pukuten2,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Ship,Futagotenshi)
		);
	monsterRepo[Pumpmon] = 
		MonsterRef(
			Pumpmon,
			pumpmon1,pumpmon2,pumpmon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Sabotenshi] = 
		MonsterRef(
			Sabotenshi,
			sabotenshi1,sabotenshi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship)
		);
	monsterRepo[Sabreleomon] = 
		MonsterRef(
			Sabreleomon,
			sabreleomon1,sabreleomon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Salamon] = 
		MonsterRef(
			Salamon,
			salamon1,salamon2,salamon3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Tailmon,Unimon)
		);
	monsterRepo[Seadramon] = 
		MonsterRef(
			Seadramon,
			seadramon1,seadramon2,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Megaseadramon)
		);
	monsterRepo[Seraphimon] = 
		MonsterRef(
			Seraphimon,
			seraphimon1,seraphimon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Shakomon] = 
		MonsterRef(
			Shakomon,
			shakomon1,shakomon2,shakomon3,
			MOVER,
			TEEN_STAGE,
			oceanTrue,
			MonsterList(Dolphmon,Shellmon,Gesomon)
		);
	monsterRepo[Shellmon] = 
		MonsterRef(
			Shellmon,
			shellmon1,shellmon2,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Whamon,Megaseadramon)
		);
	monsterRepo[Ship] = 
		MonsterRef(
			Ship,
			ship1,ship2,
			MOVER,
			DEATH_STAGE,
			oceanFalse,
			MonsterList(Digiegg,Tamaegg,Oceanegg)
		);
	monsterRepo[Shirobabytchi] = 
		MonsterRef(
			Shirobabytchi,
			shirobabytchi1,shirobabytchi2,
			MOVER,
			BABY_STAGE,
			oceanFalse,
			MonsterList(Kinakomotchi,Marutchi)
		);
	monsterRepo[Sukamon] = 
		MonsterRef(
			Sukamon,
			sukamon1,sukamon2,sukamon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Extyranomon,Giromon,Vademon)
		);
	monsterRepo[Tailmon] = 
		MonsterRef(
			Tailmon,
			tailmon1,tailmon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Angewomon,Ladydevimon,Andiramon)
		);
	monsterRepo[Taiyakitchi] = 
		MonsterRef(
			Taiyakitchi,
			taiyakitchi1,taiyakitchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Takotchi] = 
		MonsterRef(
			Takotchi,
			takotchi1,takotchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Takoten] = 
		MonsterRef(
			Takoten,
			takoten1,takoten2,takoten3,
			FLOATER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Pukuten,Taraten)
		);
	monsterRepo[Tamaegg] =
		MonsterRef(
			Tamaegg,
			tamaegg1,tamaegg2,tamaegg3,
			EGG,
			EGG_STAGE,
			oceanFalse,
			MonsterList(Babytchi,Shirobabytchi)
		);
	monsterRepo[Tamatchi] = 
		MonsterRef(
			Tamatchi,
			tamatchi1,tamatchi2,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Masktchi,Ginjirotchi,Bunbuntchi,Kuchipatchi)
		);
	monsterRepo[Tarakotchi] = 
		MonsterRef(
			Tarakotchi,
			tarakotchi1,tarakotchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Taraten] = 
		MonsterRef(
			Taraten,
			taraten1,taraten2,
			FLOATER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Sabotenshi,Ship,Ship)
		);
	monsterRepo[Tentomon] = 
		MonsterRef(
			Tentomon,
			tentomon1,tentomon2,tentomon3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Kabuterimon,Kabuterimon,Kuwagamon,Flymon)
		);
	monsterRepo[Tokomon] = 
		MonsterRef(
			Tokomon,
			tokomon1,tokomon2,tokomon3,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Patamon,Salamon,Picodevimon)
		);
	monsterRepo[Tongaritchi] = 
		MonsterRef(
			Tongaritchi,
			tongaritchi1,tongaritchi2,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Hashizotchi,Dorotchi,Memetchi,Pochitchi)
		);
	monsterRepo[Tonmarutchi] = 
		MonsterRef(
			Tonmarutchi,
			tonmarutchi1,tonmarutchi2,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Oniontchi,Hashitamatchi,Hikotchi)
		);
	monsterRepo[Tsunomon] = 
		MonsterRef(
			Tsunomon,
			tsunomon1,tsunomon2,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Gabumon,Elecmon)
		);
	monsterRepo[Tyranomon] = 
		MonsterRef(
			Tyranomon,
			tyranomon1,tyranomon2,tyranomon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Megadramon,Metaltyranomon,Metaltyranomon,Mamemon)
		);
	monsterRepo[Ufotchi] = 
		MonsterRef(
			Ufotchi,
			ufotchi1,ufotchi2,ufotchi3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Bunbuntchi,Dorotchi,Zuccitchi,Memetchi)
		);
	monsterRepo[Unimon] = 
		MonsterRef(
			Unimon,
			unimon1,unimon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Andromon,Giromon,Etemon)
		);
	monsterRepo[Vademon] = 
		MonsterRef(
			Vademon,
			vademon1,vademon2,vademon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Mainframe)
		);
	monsterRepo[Vamdemon] = 
		MonsterRef(
			Vamdemon,
			vamdemon1,vamdemon2,vamdemon3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Demon,Demon,Demon,Mainframe)
		);
	monsterRepo[Wargreymon] = 
		MonsterRef(
			Wargreymon,
			wargreymon1,wargreymon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Omegamon,Omegamon,Omegamon,Mainframe)
		);
	monsterRepo[Weregarurumon] = 
		MonsterRef(
			Weregarurumon,
			weregarurumon1,weregarurumon2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Metalgarurumon)
		);
	monsterRepo[Whamon] = 
		MonsterRef(
			Whamon,
			whamon1,whamon2,whamon3,
			FLOATER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Metalpiranimon,Mainframe)
		);
	monsterRepo[Wooltchi] = 
		MonsterRef(
			Wooltchi,
			wooltchi1,wooltchi2,wooltchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Youngmametchi] = 
		MonsterRef(
			Youngmametchi,
			youngmametchi1,youngmametchi2,youngmametchi3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Mametchi,Masktchi,Masukutchi,Gozarutchi)
		);
	monsterRepo[Youngmimitchi] = 
		MonsterRef(
			Youngmimitchi,
			youngmimitchi1,youngmimitchi2,youngmimitchi3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Mimitchi,Memetchi,Pochitchi,Wooltchi)
		);
	monsterRepo[Zatchi] = 
		MonsterRef(
			Zatchi,
			zatchi1,zatchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Grave)
		);
	monsterRepo[Zuccitchi] = 
		MonsterRef(
			Zuccitchi,
			zuccitchi1,zuccitchi2,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Ship,Zatchi,Zatchi)
		);
	monsterRepo[Zudomon] = 
		MonsterRef(
			Zudomon,
			zudomon1,zudomon2,
			MOVER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Mainframe)
		);
	monsterRepo[Zukidebitchi] = 
		MonsterRef(
			Zukidebitchi,
			zukidebitchi1,zukidebitchi2,zukidebitchi3,
			MOVER,
			CHILD_STAGE,
			oceanFalse,
			MonsterList(Ghostdeviltchi,Oyajidebiru)
		);
	
	//END NEW

}

const uint8_t * MonsterDB::getSprite1(MonsterName name){
  return monsterRepo[name].bmp1;
}

const uint8_t * MonsterDB::getSprite2(MonsterName name){
  return monsterRepo[name].bmp2;
}

const uint8_t * MonsterDB::getSprite3(MonsterName name){
  return monsterRepo[name].bmp3;
}

MonsterType MonsterDB::getMonsterType(MonsterName name){
  return monsterRepo[name].monsterType;
}

MonsterStage MonsterDB::getMonsterStage(MonsterName name){
  return monsterRepo[name].monsterStage;
}

bool MonsterDB::isUnderwater(MonsterName name){
  return monsterRepo[name].oceanType;
}

Monster* MonsterDB::newMonster(MonsterName name){
  switch(getMonsterType(name)){
    case EGG:
      return new Egg(monsterRepo[name],0);
    case MOVER:
      return new MoverMon(monsterRepo[name],0);
      break;
    case SITTER:
      return new Sitter(monsterRepo[name],0);
      break;
	case SHY_SITTER:
	  return new ShySitter(monsterRepo[name],0);
      break;
    case FLOATER:
      return new FloaterMon(monsterRepo[name],0);
      break;
  }
  return NULL;
}

ScreenFX* MonsterDB::newFX(FXType fx){
  switch(fx){
    case FLUSH_FX:
      return new FlusherFX();
      break;
    case BUBBLE_FX:
      return new BubbleFX();
      break;
    case EVOLVE_FX:
      return new EvolveFX();
      break;
	case SNOW_FX:
      return new SnowFX();
      break;
	case LAST_FX:
	  Serial.println("Attempting to create LAST_FX, something is wrong.");
	  return new SnowFX();
	  break;
	default:
	  Serial.println("newFX is defaulting. Something is wrong.");
	  return new SnowFX();
  }
}

MonsterName MonsterDB::getRandomMonster(MonsterName name){
  MonsterName rando;
  do{
    rando = static_cast<MonsterName>(random(LAST_MON_NAME));
  }while(getMonsterStage(rando) != getMonsterStage(name) || isUnderwater(rando) != isUnderwater(name));
  return rando;
}
