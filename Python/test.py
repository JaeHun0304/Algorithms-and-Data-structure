import unittest
import primitivetypes as pt



class TestBitWise(unittest.TestCase):
	def test_countbits(self):
		message1 = "please pass the number which is not 0"
		message2 = "please pass the positive number"
		self.assertEqual(message1, pt.CountBits(0))
		self.assertEqual(2, pt.CountBits(17))
		self.assertEqual(message2, pt.CountBits(-2))



if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestBitWise)
    unittest.TextTestRunner(verbosity=2).run(suite)
