#include "Animation_Portail.h"

void Animation_Portail::Init_animation_portail()
{
    this->frameRec = { 0.0f, 0.0f, 100, 100 };


    this->Portail01 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_01.png");
    this->Portail02 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_02.png");
    this->Portail03 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_03.png");
    this->Portail04 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_04.png");
    this->Portail05 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_05.png");
    this->Portail06 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_06.png");
    this->Portail07 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_07.png");
    this->Portail08 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_08.png");
    this->Portail09 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_09.png");

    this->Portail10 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_10.png");
    this->Portail11 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_11.png");
    this->Portail12 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_12.png");
    this->Portail13 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_13.png");
    this->Portail14 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_14.png");
    this->Portail15 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_15.png");
    this->Portail16 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_16.png");
    this->Portail17 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_17.png");
    this->Portail18 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_18.png");
    this->Portail19 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_19.png");

    this->Portail20 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_20.png");
    this->Portail21 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_21.png");
    this->Portail22 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_22.png");
    this->Portail23 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_23.png");
    this->Portail24 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_24.png");
    this->Portail25 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_25.png");
    this->Portail26 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_26.png");
    this->Portail27 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_27.png");
    this->Portail28 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_28.png");
    this->Portail29 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_29.png");

    this->Portail30 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_30.png");
    this->Portail31 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_31.png");
    this->Portail32 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_32.png");
    this->Portail33 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_33.png");
    this->Portail34 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_34.png");
    this->Portail35 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_35.png");
    this->Portail36 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_36.png");
    this->Portail37 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_37.png");
    this->Portail38 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_38.png");
    this->Portail39 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_39.png");

    this->Portail40 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_40.png");
    this->Portail41 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_41.png");
    this->Portail42 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_42.png");
    this->Portail43 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_43.png");
    this->Portail44 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_44.png");
    this->Portail45 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_45.png");
    this->Portail46 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_46.png");
    this->Portail47 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_47.png");
    this->Portail48 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_48.png");
    this->Portail49 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_49.png");

    this->Portail50 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_50.png");
    this->Portail51 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_51.png");
    this->Portail52 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_52.png");
    this->Portail53 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_53.png");
    this->Portail54 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_54.png");
    this->Portail55 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_55.png");
    this->Portail56 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_56.png");
    this->Portail57 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_57.png");
    this->Portail58 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_58.png");
    this->Portail59 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_59.png");

    this->Portail60 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_60.png");
    this->Portail61 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_61.png");
    this->Portail62 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_62.png");
    this->Portail63 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_63.png");
    this->Portail64 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_64.png");
    this->Portail65 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_65.png");
    this->Portail66 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_66.png");
    this->Portail67 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_67.png");
    this->Portail68 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_68.png");
    this->Portail69 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_69.png");

    this->Portail70 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_70.png");
    this->Portail71 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_71.png");
    this->Portail72 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_72.png");
    this->Portail73 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_73.png");
    this->Portail74 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_74.png");
    this->Portail75 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_75.png");
    this->Portail76 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_76.png");
    this->Portail77 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_77.png");
    this->Portail78 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_78.png");
    this->Portail79 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_79.png");

    this->Portail80 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_80.png");
    this->Portail81 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_81.png");
    this->Portail82 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_82.png");
    this->Portail83 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_83.png");
    this->Portail84 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_84.png");
    this->Portail85 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_85.png");
    this->Portail86 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_86.png");
    this->Portail87 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_87.png");
    this->Portail88 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_88.png");
    this->Portail89 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_89.png");
   
    this->Portail90 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_90.png");
    this->Portail91 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_91.png");
    this->Portail92 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_92.png");
    this->Portail93 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_93.png");
    this->Portail94 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_94.png");
    this->Portail95 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_95.png");
    this->Portail96 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_96.png");
    this->Portail97 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_97.png");
    this->Portail98 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_98.png");
    this->Portail99 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_99.png");

    this->Portail100 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_100.png");
    this->Portail101 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_101.png");
    this->Portail102 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_102.png");
    this->Portail103 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_103.png");
    this->Portail104 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_104.png");
    this->Portail105 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_105.png");
    this->Portail106 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_106.png");
    this->Portail107 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_107.png");
    this->Portail108 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_108.png");
    this->Portail109 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_109.png");

    this->Portail110 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_110.png");
    this->Portail111 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_111.png");
    this->Portail112 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_112.png");
    this->Portail113 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_113.png");
    this->Portail114 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_114.png");
    this->Portail115 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_115.png");
    this->Portail116 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_116.png");
    this->Portail117 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_117.png");
    this->Portail118 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_118.png");
    this->Portail119 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_119.png");

    this->Portail120 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_120.png");
    this->Portail121 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_121.png");
    this->Portail122 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_122.png");
    this->Portail123 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_123.png");
    this->Portail124 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_124.png");
    this->Portail125 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_125.png");
    this->Portail126 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_126.png");
    this->Portail127 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_127.png");
    this->Portail128 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_128.png");
    this->Portail129 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_129.png");

    this->Portail130 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_130.png");
    this->Portail131 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_131.png");
    this->Portail132 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_132.png");
    this->Portail133 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_133.png");
    this->Portail134 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_134.png");
    this->Portail135 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_135.png");
    this->Portail136 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_136.png");
    this->Portail137 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_137.png");
    this->Portail138 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_138.png");
    this->Portail139 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_139.png");

    this->Portail140 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_140.png");
    this->Portail141 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_141.png");
    this->Portail142 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_142.png");
    this->Portail143 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_143.png");
    this->Portail144 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_144.png");
    this->Portail145 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_145.png");
    this->Portail146 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_146.png");
    this->Portail147 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_147.png");
    this->Portail148 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_148.png");
    this->Portail149 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_149.png");

    this->Portail150 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/portail/convert_150.png");
}

void Animation_Portail::animation_portail(Vector2 position, int currentFrame)
{
}
