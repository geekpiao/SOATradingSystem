// main.cpp
// 
// The main function

// please set the corresponding path (".../tradingsystem")
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "soa.hpp"
#include "products.hpp"
#include "productservice.hpp"
#include "Data/BondPriceDataGenerator.hpp"
#include "Data/BondTradeDataGenerator.hpp"
#include "Data/BondMarketDataGenerator.hpp"
#include "Data/BondInquiryDataGenerator.hpp"
#include "BondService/BondAlgoExecutionSoa.hpp"
#include "BondService/BondAlgoStreamingSoa.hpp"
#include "BondService/BondExecutionSoa.hpp"
#include "BondService/BondGUIService.hpp"
#include "BondService/BondMarketDataSoa.hpp"
#include "BondService/BondInquirySoa.hpp"
#include "BondService/BondPositionSoa.hpp"
#include "BondService/BondPricingSoa.hpp"
#include "BondService/BondRiskSoa.hpp"
#include "BondService/BondStreamingSoa.hpp"
#include "BondService/BondTradeBookingSoa.hpp"
#include "BondService/HistoricalDataSoa/BondExecutionHistoricalDataSoa.hpp"
#include "BondService/HistoricalDataSoa/BondInquiryHistoricalDataSoa.hpp"
#include "BondService/HistoricalDataSoa/BondPositionHistoricalDataSoa.hpp"
#include "BondService/HistoricalDataSoa/BondRiskHistoricalDataSoa.hpp"
#include "BondService/HistoricalDataSoa/BondStreamingHistoricalDataSoa.hpp"
#include "StopWatch.hpp"

int main()
{

	std::cout << "=================== I. Setup ========================\n";

	// define the path of the files (subject to change)
	// the following may differ between Windows and Unix
	// input files
	std::string tradeinputPath("./Data/trade.txt");
	std::string priceinputPath("./Data/price.txt");
	std::string marketdatainputPath("./Data/marketdata.txt");
	std::string inquiryinputPath("./Data/inquiry.txt");
	// output files
	std::string positionoutputPath("./Data/position.txt");
	std::string riskoutputPath("./Data/risk.txt");
	std::string streamoutputPath("./Data/streaming.txt");
	std::string guioutputPath("./Data/gui.txt");
	std::string executionoutputPath("./Data/execution.txt");
	std::string inquiryoutputPath("./Data/allinquiry.txt");

	// product information (Used data upto 11/30/2024)
	Bond treasury2Y("912828YU8", CUSIP, "T", 1.625,
                    boost::gregorian::date(2026,Nov,30)); // 2Y bond
	Bond treasury3Y("91282CAY7", CUSIP, "T", 0.625,
                    boost::gregorian::date(2027,Nov,30)); // 3Y bond
	Bond treasury5Y("91282CFY2", CUSIP, "T", 3.875,
                    boost::gregorian::date(2029,Nov,30)); // 5Y bond
	Bond treasury7Y("91282CDJ7", CUSIP, "T", 1.375,
                    boost::gregorian::date(2031,Nov,15)); // 7Y bond
	Bond treasury10Y("91282CLW9", CUSIP, "T", 4.250,
                     boost::gregorian::date(2034,Nov,15)); // 10Y bond
	Bond treasury20Y("912810RJ9", CUSIP, "T", 3.000,
                     boost::gregorian::date(2044,Nov,15)); // 20Y bond
	Bond treasury30Y("912810UE6", CUSIP, "T", 4.500,
                     boost::gregorian::date(2054,Nov,15)); // 30Y bond

	// bond product service
	BondProductService bondProductService;
	bondProductService.Add(treasury2Y);
	bondProductService.Add(treasury3Y);
	bondProductService.Add(treasury5Y);
	bondProductService.Add(treasury7Y);
	bondProductService.Add(treasury10Y);
	bondProductService.Add(treasury20Y);
	bondProductService.Add(treasury30Y);

	// pv01 information (hard-coded) (latest data)
	std::unordered_map<string,double> pv01Treasury;
	pv01Treasury.insert(std::make_pair(treasury2Y.GetProductId(), 0.0185));
	pv01Treasury.insert(std::make_pair(treasury3Y.GetProductId(), 0.0260));
	pv01Treasury.insert(std::make_pair(treasury5Y.GetProductId(), 0.0376));
	pv01Treasury.insert(std::make_pair(treasury7Y.GetProductId(), 0.0505));
	pv01Treasury.insert(std::make_pair(treasury10Y.GetProductId(), 0.0637));
	pv01Treasury.insert(std::make_pair(treasury20Y.GetProductId(), 0.1195));
	pv01Treasury.insert(std::make_pair(treasury30Y.GetProductId(), 0.2019));

	// bucketed sector information
	std::vector<std::string> frontEnd = { treasury2Y.GetProductId() , treasury3Y.GetProductId() }; // front end
	std::vector<std::string> belly = { treasury5Y.GetProductId() , treasury7Y.GetProductId(), treasury10Y.GetProductId() }; // belly
	std::vector<std::string> longEnd = { treasury30Y.GetProductId() }; // long end
	std::unordered_map<std::string, std::vector<std::string>> bucketTreasury;
	bucketTreasury.insert(std::make_pair("FrontEnd", frontEnd));
	bucketTreasury.insert(std::make_pair("Belly", belly));
	bucketTreasury.insert(std::make_pair("LongEnd", longEnd));

	// define a stop watch to record the time
	StopWatch sw;

	std::cout << "=====================================================\n";

	std::cout << "=================== II. Generate data ========================\n";

	// generate data
	sw.StartStopWatch();
	bond_trade_generator(tradeinputPath, &bondProductService, "T"); // trade.txt
	sw.StopStopWatch();
	std::cout << "Time for trade.txt: " << sw.GetTime() << " seconds\n\n";
	sw.Reset();

	sw.StartStopWatch();
	bond_price_generator(priceinputPath, &bondProductService, "T"); // price.txt
	sw.StopStopWatch();
	std::cout << "Time for price.txt: " << sw.GetTime() << " seconds\n\n";
	sw.Reset();

	sw.StartStopWatch();
	bond_market_data_generator(marketdatainputPath, &bondProductService, "T"); // marketdata.txt
	sw.StopStopWatch();
	std::cout << "Time for marketdata.txt: " << sw.GetTime() << " seconds\n\n";
	sw.Reset();

	sw.StartStopWatch();
	bond_inquiry_generator(inquiryinputPath, &bondProductService, "T"); // inquiry.txt
	sw.StopStopWatch();
	std::cout << "Time for inquiry.txt: " << sw.GetTime() << " seconds\n\n";
	sw.Reset();

	std::cout << "==============================================================\n";

	std::cout << "=================== III. Run services ========================\n";

	std::cout << "(a) trade.txt ==> position.txt and risk.txt\n";

	// build service components
	BondTradeBookingService bondTradeBookingService;
	BondPositionService bondPositionService(&bondProductService, "T");
	BondPositionListener bondPositionListener(&bondPositionService);
 	BondRiskService bondRiskService(&bondProductService, pv01Treasury);
	BondRiskListener bondRiskListener(&bondRiskService);
	BondRiskHistoricalDataConnector bondRiskHistoricalDataConnector(riskoutputPath);
	BondRiskHistoricalDataService bondRiskHistoricalDataService(&bondRiskHistoricalDataConnector);
	BondRiskHistoricalDataListener bondRiskHistoricalDataListener(&bondProductService, 
		&bondRiskHistoricalDataService, &bondRiskService, bucketTreasury);
	BondPositionHistoricalDataConnector bondPositionHistoricalDataConnector(positionoutputPath);
	BondPositionHistoricalDataService bondPositionHistoricalDataService(&bondPositionHistoricalDataConnector);
	BondPositionHistoricalDataListener bondPositionHistoricalDataListener(&bondPositionHistoricalDataService);

	// link the service components
	bondTradeBookingService.AddListener(&bondPositionListener);
	bondPositionService.AddListener(&bondRiskListener);
	bondPositionService.AddListener(&bondPositionHistoricalDataListener);
	bondRiskService.AddListener(&bondRiskHistoricalDataListener);

	// start
	sw.StartStopWatch();
	BondTradeBookingConnector bondTradeBookingConnector(tradeinputPath, &bondTradeBookingService, &bondProductService);
	sw.StopStopWatch();
	std::cout << "Time elapse: " << sw.GetTime() << " seconds\n\n";
	sw.Reset();

	std::cout << "(b) price.txt ==> streaming.txt and gui.txt\n";

	// build service components
	int throttleVal = 300; // miliseconds
	BondPricingService bondPricingService;
	BondAlgoStreamingService bondAlgoStreamingService;
	BondAlgoStreamingListener bondAlgoStreamingListener(&bondAlgoStreamingService);
	BondStreamingService bondStreamingService;
	BondStreamingListener bondStreamingListener(&bondStreamingService);
	BondStreamingHistoricalDataConnector bondStreamingHistoricalDataConnector(streamoutputPath);
	BondStreamingHistoricalDataService bondStreamingHistoricalDataService(&bondStreamingHistoricalDataConnector);
	BondStreamingHistoricalDataListener bondStreamingHistoricalDataListener(&bondStreamingHistoricalDataService);
	BondGUIConnector bondGUIConnector(guioutputPath);
	BondGUIService bondGUIService(throttleVal, &bondGUIConnector);
	BondGUIListener bondGUIListener(&bondGUIService);

	// link the service components
	bondPricingService.AddListener(&bondAlgoStreamingListener);
	bondPricingService.AddListener(&bondGUIListener);
	bondAlgoStreamingService.AddListener(&bondStreamingListener);
	bondStreamingService.AddListener(&bondStreamingHistoricalDataListener);

	// start
	sw.StartStopWatch();
	BondPricingConnector bondPricingConnector(priceinputPath, &bondPricingService, &bondProductService);
	sw.StopStopWatch();
	std::cout << "Time elapse: " << sw.GetTime() << " seconds\n\n";
	sw.Reset();

	std::cout << "(c) marketdata.txt ==> execution.txt, position.txt and risk.txt\n";

	// build service components
	BondMarketDataService bondMarketDataService;
	BondAlgoExecutionService bondAlgoExecutionService;
	BondAlgoExecutionListener bondAlgoExecutionListener(&bondAlgoExecutionService);
	BondExecutionService bondExecutionService;
	BondExecutionListener bondExecutionListener(&bondExecutionService);
	BondTradeBookingListener bondTradeBookingListener(&bondTradeBookingService);
	BondExecutionHistoricalDataConnector bondExecutionHistoricalDataConnector(executionoutputPath);
	BondExecutionHistoricalDataService bondExecutionHistoricalDataService(&bondExecutionHistoricalDataConnector);
	BondExecutionHistoricalDataListener bondExecutionHistoricalDataListener(&bondExecutionHistoricalDataService);

	// link the service components
	bondMarketDataService.AddListener(&bondAlgoExecutionListener);
	bondAlgoExecutionService.AddListener(&bondExecutionListener);
	bondExecutionService.AddListener(&bondTradeBookingListener);
	bondExecutionService.AddListener(&bondExecutionHistoricalDataListener);
	
	// start
	sw.StartStopWatch();
	//BondMarketDataConnector bondMarketDataConnector(marketdatainputPath, &bondMarketDataService, &bondProductService);
	sw.StopStopWatch();
	std::cout << "Time elapse: " << sw.GetTime() << " seconds\n\n";
	sw.Reset();

	std::cout << "(d) inquiry.txt ==> allinquiry.txt\n";

	// build service components
	BondInquiryService bondInquiryService;
	BondInquiryListener bondInquiryListener(&bondInquiryService);
	BondInquiryHistoricalDataConnector bondInquiryHistoricalDataConnector(inquiryoutputPath);
	BondInquiryHistoricalDataService bondInquiryHistoricalDataService(&bondInquiryHistoricalDataConnector);
	BondInquiryHistoricalDataListener bondInquiryHistoricalDataListener(&bondInquiryHistoricalDataService);

	// link the service components
	bondInquiryService.AddListener(&bondInquiryHistoricalDataListener);
	bondInquiryService.AddListener(&bondInquiryListener);

	// start
	sw.StartStopWatch();
	BondInquiryConnector bondInquiryConnector(inquiryinputPath, &bondInquiryService, &bondProductService);
	sw.StopStopWatch();
	std::cout << "Time elapse: " << sw.GetTime() << " seconds\n\n";
	sw.Reset();

	std::cout << "==============================================================\n";


	return 0;
}