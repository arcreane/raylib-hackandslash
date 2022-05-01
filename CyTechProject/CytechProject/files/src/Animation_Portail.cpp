#include "../includes/Animation_Portail.h"

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

    if (currentFrame == 1) DrawTextureRec(this->Portail01, this->frameRec, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Portail02, this->frameRec, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Portail03, this->frameRec, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Portail04, this->frameRec, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->Portail05, this->frameRec, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->Portail06, this->frameRec, position, WHITE);
    if (currentFrame == 7) DrawTextureRec(this->Portail07, this->frameRec, position, WHITE);
    if (currentFrame == 8) DrawTextureRec(this->Portail08, this->frameRec, position, WHITE);
    if (currentFrame == 9) DrawTextureRec(this->Portail09, this->frameRec, position, WHITE);

    if (currentFrame == 10) DrawTextureRec(this->Portail10, this->frameRec, position, WHITE);
    if (currentFrame == 11) DrawTextureRec(this->Portail11, this->frameRec, position, WHITE);
    if (currentFrame == 12) DrawTextureRec(this->Portail12, this->frameRec, position, WHITE);
    if (currentFrame == 13) DrawTextureRec(this->Portail13, this->frameRec, position, WHITE);
    if (currentFrame == 14) DrawTextureRec(this->Portail14, this->frameRec, position, WHITE);
    if (currentFrame == 15) DrawTextureRec(this->Portail15, this->frameRec, position, WHITE);
    if (currentFrame == 16) DrawTextureRec(this->Portail16, this->frameRec, position, WHITE);
    if (currentFrame == 17) DrawTextureRec(this->Portail17, this->frameRec, position, WHITE);
    if (currentFrame == 18) DrawTextureRec(this->Portail18, this->frameRec, position, WHITE);
    if (currentFrame == 19) DrawTextureRec(this->Portail19, this->frameRec, position, WHITE);

    if (currentFrame == 20) DrawTextureRec(this->Portail20, this->frameRec, position, WHITE);
    if (currentFrame == 21) DrawTextureRec(this->Portail21, this->frameRec, position, WHITE);
    if (currentFrame == 22) DrawTextureRec(this->Portail22, this->frameRec, position, WHITE);
    if (currentFrame == 23) DrawTextureRec(this->Portail23, this->frameRec, position, WHITE);
    if (currentFrame == 24) DrawTextureRec(this->Portail24, this->frameRec, position, WHITE);
    if (currentFrame == 25) DrawTextureRec(this->Portail25, this->frameRec, position, WHITE);
    if (currentFrame == 26) DrawTextureRec(this->Portail26, this->frameRec, position, WHITE);
    if (currentFrame == 27) DrawTextureRec(this->Portail27, this->frameRec, position, WHITE);
    if (currentFrame == 28) DrawTextureRec(this->Portail28, this->frameRec, position, WHITE);
    if (currentFrame == 29) DrawTextureRec(this->Portail29, this->frameRec, position, WHITE);

    if (currentFrame == 30) DrawTextureRec(this->Portail30, this->frameRec, position, WHITE);
    if (currentFrame == 31) DrawTextureRec(this->Portail31, this->frameRec, position, WHITE);
    if (currentFrame == 32) DrawTextureRec(this->Portail32, this->frameRec, position, WHITE);
    if (currentFrame == 33) DrawTextureRec(this->Portail33, this->frameRec, position, WHITE);
    if (currentFrame == 34) DrawTextureRec(this->Portail34, this->frameRec, position, WHITE);
    if (currentFrame == 35) DrawTextureRec(this->Portail35, this->frameRec, position, WHITE);
    if (currentFrame == 36) DrawTextureRec(this->Portail36, this->frameRec, position, WHITE);
    if (currentFrame == 37) DrawTextureRec(this->Portail37, this->frameRec, position, WHITE);
    if (currentFrame == 38) DrawTextureRec(this->Portail38, this->frameRec, position, WHITE);
    if (currentFrame == 39) DrawTextureRec(this->Portail39, this->frameRec, position, WHITE);

    if (currentFrame == 40) DrawTextureRec(this->Portail40, this->frameRec, position, WHITE);
    if (currentFrame == 41) DrawTextureRec(this->Portail41, this->frameRec, position, WHITE);
    if (currentFrame == 42) DrawTextureRec(this->Portail42, this->frameRec, position, WHITE);
    if (currentFrame == 43) DrawTextureRec(this->Portail43, this->frameRec, position, WHITE);
    if (currentFrame == 44) DrawTextureRec(this->Portail44, this->frameRec, position, WHITE);
    if (currentFrame == 45) DrawTextureRec(this->Portail45, this->frameRec, position, WHITE);
    if (currentFrame == 46) DrawTextureRec(this->Portail46, this->frameRec, position, WHITE);
    if (currentFrame == 47) DrawTextureRec(this->Portail47, this->frameRec, position, WHITE);
    if (currentFrame == 48) DrawTextureRec(this->Portail48, this->frameRec, position, WHITE);
    if (currentFrame == 49) DrawTextureRec(this->Portail49, this->frameRec, position, WHITE);

    if (currentFrame == 50) DrawTextureRec(this->Portail50, this->frameRec, position, WHITE);
    if (currentFrame == 51) DrawTextureRec(this->Portail51, this->frameRec, position, WHITE);
    if (currentFrame == 52) DrawTextureRec(this->Portail52, this->frameRec, position, WHITE);
    if (currentFrame == 53) DrawTextureRec(this->Portail53, this->frameRec, position, WHITE);
    if (currentFrame == 54) DrawTextureRec(this->Portail54, this->frameRec, position, WHITE);
    if (currentFrame == 55) DrawTextureRec(this->Portail55, this->frameRec, position, WHITE);
    if (currentFrame == 56) DrawTextureRec(this->Portail56, this->frameRec, position, WHITE);
    if (currentFrame == 57) DrawTextureRec(this->Portail57, this->frameRec, position, WHITE);
    if (currentFrame == 58) DrawTextureRec(this->Portail58, this->frameRec, position, WHITE);
    if (currentFrame == 59) DrawTextureRec(this->Portail59, this->frameRec, position, WHITE);

    if (currentFrame == 60) DrawTextureRec(this->Portail60, this->frameRec, position, WHITE);
    if (currentFrame == 61) DrawTextureRec(this->Portail61, this->frameRec, position, WHITE);
    if (currentFrame == 62) DrawTextureRec(this->Portail62, this->frameRec, position, WHITE);
    if (currentFrame == 63) DrawTextureRec(this->Portail63, this->frameRec, position, WHITE);
    if (currentFrame == 64) DrawTextureRec(this->Portail64, this->frameRec, position, WHITE);
    if (currentFrame == 65) DrawTextureRec(this->Portail65, this->frameRec, position, WHITE);
    if (currentFrame == 66) DrawTextureRec(this->Portail66, this->frameRec, position, WHITE);
    if (currentFrame == 67) DrawTextureRec(this->Portail67, this->frameRec, position, WHITE);
    if (currentFrame == 68) DrawTextureRec(this->Portail68, this->frameRec, position, WHITE);
    if (currentFrame == 69) DrawTextureRec(this->Portail69, this->frameRec, position, WHITE);

    if (currentFrame == 70) DrawTextureRec(this->Portail70, this->frameRec, position, WHITE);
    if (currentFrame == 71) DrawTextureRec(this->Portail71, this->frameRec, position, WHITE);
    if (currentFrame == 72) DrawTextureRec(this->Portail72, this->frameRec, position, WHITE);
    if (currentFrame == 73) DrawTextureRec(this->Portail73, this->frameRec, position, WHITE);
    if (currentFrame == 74) DrawTextureRec(this->Portail74, this->frameRec, position, WHITE);
    if (currentFrame == 75) DrawTextureRec(this->Portail75, this->frameRec, position, WHITE);
    if (currentFrame == 76) DrawTextureRec(this->Portail76, this->frameRec, position, WHITE);
    if (currentFrame == 77) DrawTextureRec(this->Portail77, this->frameRec, position, WHITE);
    if (currentFrame == 78) DrawTextureRec(this->Portail78, this->frameRec, position, WHITE);
    if (currentFrame == 79) DrawTextureRec(this->Portail79, this->frameRec, position, WHITE);

    if (currentFrame == 80) DrawTextureRec(this->Portail80, this->frameRec, position, WHITE);
    if (currentFrame == 81) DrawTextureRec(this->Portail81, this->frameRec, position, WHITE);
    if (currentFrame == 82) DrawTextureRec(this->Portail82, this->frameRec, position, WHITE);
    if (currentFrame == 83) DrawTextureRec(this->Portail83, this->frameRec, position, WHITE);
    if (currentFrame == 84) DrawTextureRec(this->Portail84, this->frameRec, position, WHITE);
    if (currentFrame == 85) DrawTextureRec(this->Portail85, this->frameRec, position, WHITE);
    if (currentFrame == 86) DrawTextureRec(this->Portail86, this->frameRec, position, WHITE);
    if (currentFrame == 87) DrawTextureRec(this->Portail87, this->frameRec, position, WHITE);
    if (currentFrame == 88) DrawTextureRec(this->Portail88, this->frameRec, position, WHITE);
    if (currentFrame == 89) DrawTextureRec(this->Portail89, this->frameRec, position, WHITE);

    if (currentFrame == 90) DrawTextureRec(this->Portail90, this->frameRec, position, WHITE);
    if (currentFrame == 91) DrawTextureRec(this->Portail91, this->frameRec, position, WHITE);
    if (currentFrame == 92) DrawTextureRec(this->Portail92, this->frameRec, position, WHITE);
    if (currentFrame == 93) DrawTextureRec(this->Portail93, this->frameRec, position, WHITE);
    if (currentFrame == 94) DrawTextureRec(this->Portail94, this->frameRec, position, WHITE);
    if (currentFrame == 95) DrawTextureRec(this->Portail95, this->frameRec, position, WHITE);
    if (currentFrame == 96) DrawTextureRec(this->Portail96, this->frameRec, position, WHITE);
    if (currentFrame == 97) DrawTextureRec(this->Portail97, this->frameRec, position, WHITE);
    if (currentFrame == 98) DrawTextureRec(this->Portail98, this->frameRec, position, WHITE);
    if (currentFrame == 99) DrawTextureRec(this->Portail99, this->frameRec, position, WHITE);

    if (currentFrame == 100) DrawTextureRec(this->Portail100, this->frameRec, position, WHITE);
    if (currentFrame == 101) DrawTextureRec(this->Portail101, this->frameRec, position, WHITE);
    if (currentFrame == 102) DrawTextureRec(this->Portail102, this->frameRec, position, WHITE);
    if (currentFrame == 103) DrawTextureRec(this->Portail103, this->frameRec, position, WHITE);
    if (currentFrame == 104) DrawTextureRec(this->Portail104, this->frameRec, position, WHITE);
    if (currentFrame == 105) DrawTextureRec(this->Portail105, this->frameRec, position, WHITE);
    if (currentFrame == 106) DrawTextureRec(this->Portail106, this->frameRec, position, WHITE);
    if (currentFrame == 107) DrawTextureRec(this->Portail107, this->frameRec, position, WHITE);
    if (currentFrame == 108) DrawTextureRec(this->Portail108, this->frameRec, position, WHITE);
    if (currentFrame == 109) DrawTextureRec(this->Portail109, this->frameRec, position, WHITE);

    if (currentFrame == 110) DrawTextureRec(this->Portail110, this->frameRec, position, WHITE);
    if (currentFrame == 111) DrawTextureRec(this->Portail111, this->frameRec, position, WHITE);
    if (currentFrame == 112) DrawTextureRec(this->Portail112, this->frameRec, position, WHITE);
    if (currentFrame == 113) DrawTextureRec(this->Portail113, this->frameRec, position, WHITE);
    if (currentFrame == 114) DrawTextureRec(this->Portail114, this->frameRec, position, WHITE);
    if (currentFrame == 115) DrawTextureRec(this->Portail115, this->frameRec, position, WHITE);
    if (currentFrame == 116) DrawTextureRec(this->Portail116, this->frameRec, position, WHITE);
    if (currentFrame == 117) DrawTextureRec(this->Portail117, this->frameRec, position, WHITE);
    if (currentFrame == 118) DrawTextureRec(this->Portail118, this->frameRec, position, WHITE);
    if (currentFrame == 119) DrawTextureRec(this->Portail119, this->frameRec, position, WHITE);

    if (currentFrame == 120) DrawTextureRec(this->Portail120, this->frameRec, position, WHITE);
    if (currentFrame == 121) DrawTextureRec(this->Portail121, this->frameRec, position, WHITE);
    if (currentFrame == 122) DrawTextureRec(this->Portail122, this->frameRec, position, WHITE);
    if (currentFrame == 123) DrawTextureRec(this->Portail123, this->frameRec, position, WHITE);
    if (currentFrame == 124) DrawTextureRec(this->Portail124, this->frameRec, position, WHITE);
    if (currentFrame == 125) DrawTextureRec(this->Portail125, this->frameRec, position, WHITE);
    if (currentFrame == 126) DrawTextureRec(this->Portail126, this->frameRec, position, WHITE);
    if (currentFrame == 127) DrawTextureRec(this->Portail127, this->frameRec, position, WHITE);
    if (currentFrame == 128) DrawTextureRec(this->Portail128, this->frameRec, position, WHITE);
    if (currentFrame == 129) DrawTextureRec(this->Portail129, this->frameRec, position, WHITE);

    if (currentFrame == 130) DrawTextureRec(this->Portail130, this->frameRec, position, WHITE);
    if (currentFrame == 131) DrawTextureRec(this->Portail131, this->frameRec, position, WHITE);
    if (currentFrame == 132) DrawTextureRec(this->Portail132, this->frameRec, position, WHITE);
    if (currentFrame == 133) DrawTextureRec(this->Portail133, this->frameRec, position, WHITE);
    if (currentFrame == 134) DrawTextureRec(this->Portail134, this->frameRec, position, WHITE);
    if (currentFrame == 135) DrawTextureRec(this->Portail135, this->frameRec, position, WHITE);
    if (currentFrame == 136) DrawTextureRec(this->Portail136, this->frameRec, position, WHITE);
    if (currentFrame == 137) DrawTextureRec(this->Portail137, this->frameRec, position, WHITE);
    if (currentFrame == 138) DrawTextureRec(this->Portail138, this->frameRec, position, WHITE);
    if (currentFrame == 139) DrawTextureRec(this->Portail139, this->frameRec, position, WHITE);

    if (currentFrame == 140) DrawTextureRec(this->Portail140, this->frameRec, position, WHITE);
    if (currentFrame == 141) DrawTextureRec(this->Portail141, this->frameRec, position, WHITE);
    if (currentFrame == 142) DrawTextureRec(this->Portail142, this->frameRec, position, WHITE);
    if (currentFrame == 143) DrawTextureRec(this->Portail143, this->frameRec, position, WHITE);
    if (currentFrame == 144) DrawTextureRec(this->Portail144, this->frameRec, position, WHITE);
    if (currentFrame == 145) DrawTextureRec(this->Portail145, this->frameRec, position, WHITE);
    if (currentFrame == 146) DrawTextureRec(this->Portail146, this->frameRec, position, WHITE);
    if (currentFrame == 147) DrawTextureRec(this->Portail147, this->frameRec, position, WHITE);
    if (currentFrame == 148) DrawTextureRec(this->Portail148, this->frameRec, position, WHITE);
    if (currentFrame == 149) DrawTextureRec(this->Portail149, this->frameRec, position, WHITE);

    if (currentFrame == 150) DrawTextureRec(this->Portail150, this->frameRec, position, WHITE);
}
