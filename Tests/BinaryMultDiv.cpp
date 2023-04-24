#include <gtest/gtest.h>

#include <iostream>

#include "../Integer.cpp"
using namespace biginteger;

uint64_t Integer::BASE = 1000000000;

TEST(AbobaTest, BinaryMult_1) {
  Integer test_Integer_mult1(1), test_Integer_mult2(123);
  test_Integer_mult2 = test_Integer_mult2 * test_Integer_mult1;
  EXPECT_EQ(test_Integer_mult2.getString(), "123");

  Integer test_Integer_mult3(-1);
  test_Integer_mult2 = test_Integer_mult2 * test_Integer_mult3;
  EXPECT_EQ(test_Integer_mult2.getString(), "-123");
  test_Integer_mult2 = test_Integer_mult2 * test_Integer_mult3;
  EXPECT_EQ(test_Integer_mult2.getString(), "123");
}

TEST(AbobaTest, BinaryMult_2) {
  Integer test_Integer_mult1(0), test_Integer_mult2(382648248248);
  test_Integer_mult1 = test_Integer_mult1 * test_Integer_mult2;
  EXPECT_EQ(test_Integer_mult1.getString(), "0");

  Integer test_Integer_mult3(-274274272444);
  test_Integer_mult1 = test_Integer_mult1 * test_Integer_mult3;
  EXPECT_EQ(test_Integer_mult1.getString(), "0");
}

TEST(AbobaTest, BinaryMult_3) {
  Integer test_Integer_mult1(12356281645), test_Integer_mult2(382648248248);
  test_Integer_mult1 = test_Integer_mult1 * test_Integer_mult2;
  EXPECT_EQ(test_Integer_mult1.getString(), "4728109526318165807960");

  Integer test_Integer_mult3(-274274272444), test_Integer_mult4(5843568876444);
  test_Integer_mult3 = test_Integer_mult3 * test_Integer_mult4;
  EXPECT_EQ(test_Integer_mult3.getString(), "-1602740602063080629909136");

  Integer test_Integer_mult5(232435224353), test_Integer_mult6(-1242353241313);
  test_Integer_mult5 = test_Integer_mult5 * test_Integer_mult6;
  EXPECT_EQ(test_Integer_mult5.getString(), "-288766654370263903295489");

  Integer test_Integer_mult7(-457635482453453),
      test_Integer_mult8(-3517252876934);
  test_Integer_mult7 = test_Integer_mult7 * test_Integer_mult8;
  EXPECT_EQ(test_Integer_mult7.getString(), "1609619717246486640992353102");
}

TEST(AbobaTest, BinaryMult_4) {
  Integer test_Integer_mult1(1), test_Integer_mult2(2);
  for (int i = 0; i < 1000; ++i) {
    test_Integer_mult1 *= test_Integer_mult2;
  }
  EXPECT_EQ(test_Integer_mult1.getString(),
            "107150860718626732094842504906000181056140481170553360744375038837"
            "035105112493612249319837881569585812759467291755314682518714528569"
            "231404359845775746985748039345677748242309854210746050623711418779"
            "541821530464749835819412673987675591655439460770629145711964776865"
            "42167660429831652624386837205668069376");
}

TEST(AbobaTest, BinaryMult_5) {
  Integer test_Integer_mult1(1), test_Integer_mult2(4235463414);
  for (int i = 0; i < 100; ++i) {
    test_Integer_mult1 *= test_Integer_mult2;
  }
  EXPECT_EQ(
      test_Integer_mult1.getString(),
      "489884236647125708102201935805246470608420299303991035335819831767823696"
      "196900616017651663576761003724738435692594820803149165004250146787716137"
      "775622489936188830075005890939706592684620427940888217788296766026153973"
      "591267167883835558730395135719464808104911290907442084839611389035304687"
      "806692765728882299567254270094832030502034780950004461212341666456447799"
      "614901560272903327633977661450898578421506324222675479715716484974916648"
      "336612124687817526270729394354471680385713129737801876794975860190655960"
      "483541155204925538108659540815807168713366370381358933042074793629989252"
      "046423404260568186581642548687611493668322323096087667047187841032842820"
      "065983195026334898567041691228105426962439846967398519607914381685727703"
      "873024471680724592537703850637526690642375895791550460765443630989504744"
      "222471390476261782584348588933086520067912573612347237542854380297953924"
      "330572355746540091081652371302619904126862642861352792350171862816837983"
      "422421948184445925380325376");
}

TEST(AbobaTest, BinaryDiv_1) {
  Integer test_Integer_div_1(20);
  test_Integer_div_1 = test_Integer_div_1 / Integer(5);

  EXPECT_EQ(test_Integer_div_1.getString(), "4");

  test_Integer_div_1 = Integer(500090000000) / Integer(2);
  EXPECT_EQ(test_Integer_div_1.getString(), "2500450000000");
}

int main() {
  testing::InitGoogleTest();
  std::cout << "\nTesting: \n";
  std::cout
      << "Long Integer Laba Binary Operators\n|||||\n|||||\n|||||\nvvvvv\n";

  return RUN_ALL_TESTS();
}