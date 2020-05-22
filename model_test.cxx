#include "model.hxx"
#include <catch.hxx>

using ge211;

TEST_CASE("check board")
{
    Model m;

    std::vector<Pocket> expected {};
    CHECK(m.get_pockets() == expected);
}

 struct Test_access
 {
    Model& model;

    std::vector<Pocket>& pockets()
    {return model.pockets_;}

     Position& piece()
     {return model.piece_;}
 };

TEST_CASE("skip computer ")
{

}
